/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:18:27 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/24 16:54:22 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_hostname(t_minishell *core)
{
	char	*path;
	int		fd;
	int		bytes_read;
	char	hostname[MAX_HOSTNAME_LEN];
	
	path = "/etc/hostname";
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		core->exits.exit_code = EXIT_FAILURE;
		core->exits.exit_msg = ft_strjoin(path, ": No such file or directory");
	}
	bytes_read = read(fd, hostname, MAX_HOSTNAME_LEN);
	if (bytes_read < 0)
	{
		core->exits.exit_code = EXIT_FAILURE;
		core->exits.exit_msg = ft_strjoin(path, ": Cannot read file");
	}
	close(fd);
	hostname[bytes_read] = '\0';
	return (ft_strdup(hostname));
}

static char	*get_prompt_text(t_minishell *core)
{
	char	*user;
	char	*hostname;
	char	**pwd_split;
	char	*current_dir;
	char	*prompt;

	user = ft_strjoin_three(COLOR_WHITE, getenv("USER"), COLOR_RESET);
	hostname = get_hostname(core);
	if (ft_strchr(hostname, '.'))
		hostname = ft_split(hostname, '.')[0];
	hostname = ft_strjoin(hostname, " ");
	hostname = ft_strjoin_three(COLOR_RED, hostname, COLOR_RESET);
	pwd_split = ft_split(get_working_directory(), '/');
	current_dir = pwd_split[ft_matrix_len(pwd_split) - 1];
	current_dir = ft_strjoin_three(COLOR_CYAN, current_dir, COLOR_RESET);
	prompt = ft_strjoin(ft_strjoin("[", user), "@");
	prompt = ft_strjoin(ft_strjoin(prompt, hostname), current_dir);
	prompt = ft_strjoin(prompt, " ]$ ");
	return (prompt);
}

void	readlines(t_minishell *core)
{
	char	*prompt;

	using_history();
	while (TRUE)
	{
		prompt = get_prompt_text(core);
		core->input = readline(prompt);
		free(prompt);
		add_history(core->input);
		ft_strip(core->input);
		ft_printf("input: %s\n", core->input);
		
		if (strcmp(core->input, "pwd") == 0)
			print_working_directory(core);
		else if (strcmp(core->input, "exit") == 0)
			exit(0);

		splite_input(core);
		ft_lstclear(&core->splited_input, free);
	}
	rl_clear_history();
}
