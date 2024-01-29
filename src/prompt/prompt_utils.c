/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:09:10 by arsobrei          #+#    #+#             */
/*   Updated: 2024/01/29 16:15:32 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_hostname(t_minishell *core)
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

char	*get_username(void)
{
	char	*username;

	username = getenv("USER");
	if (!username)
	{
		username = getenv("LOGNAME");
		if (!username)
			username = "guest";
	}
	username = ft_strjoin_three(COLOR_WHITE, username, COLOR_RESET);
	return (username);
}

char	*get_prompt_text(t_minishell *core)
{
	char	*user;
	char	*hostname;
	char	**pwd_split;
	char	*current_dir;
	char	*prompt;
	char	**pp_temp;
	char	*p_temp;
	char	*final_prompt;

	user = get_username();
	hostname = get_hostname(core);
	if (ft_strchr(hostname, '.'))
	{
		pp_temp = ft_split(hostname, '.');
		free(hostname);
		hostname = ft_strdup(pp_temp[0]);
		ft_free_matrix(pp_temp);
	}
	p_temp = hostname;
	hostname = ft_strjoin_three(COLOR_RED, hostname, COLOR_RESET);
	free(p_temp);
	p_temp = hostname;
	hostname = ft_strjoin(hostname, " ");
	free(p_temp);
	current_dir = get_working_directory();
	pwd_split = ft_split(current_dir, '/');
	free(current_dir);
	current_dir = pwd_split[ft_matrix_len(pwd_split) - 1];
	current_dir = ft_strjoin_three(COLOR_CYAN, current_dir, COLOR_RESET);
	
	p_temp = ft_strjoin("[", user);
	prompt = ft_strjoin(p_temp, "@");
	free(p_temp);
	
	p_temp = ft_strjoin(prompt, hostname);
	free(prompt);
	prompt = ft_strjoin(p_temp, current_dir);
	free(p_temp);
	
	final_prompt = ft_strjoin(prompt, " ]$ ");
	free(prompt);
	free(user);
	free(hostname);
	free(current_dir);
	ft_free_matrix(pwd_split);
	return (final_prompt);
}
