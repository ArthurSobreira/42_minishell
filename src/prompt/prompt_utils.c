/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:09:10 by arsobrei          #+#    #+#             */
/*   Updated: 2024/01/29 19:15:48 by arsobrei         ###   ########.fr       */
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

char	*format_hostname(char *hostname)
{
	char	**splitted_hostname;
	char	*formatted_hostname;
	char	*c_hostname;

	splitted_hostname = NULL;
	if (ft_strchr(hostname, '.'))
	{
		splitted_hostname = ft_split(hostname, '.');
		ft_free(hostname);
		hostname = ft_strdup(splitted_hostname[0]);
		ft_free_matrix(splitted_hostname);
	}
	c_hostname = ft_strjoin_three(COLOR_RED, hostname, COLOR_RESET);
	formatted_hostname = ft_strjoin(c_hostname, " ");
	ft_free(hostname);
	ft_free(c_hostname);
	return (formatted_hostname);
}

char	*get_username(void)
{
	char	*username;
	char	*c_username;

	username = getenv("USER");
	if (!username)
	{
		username = getenv("LOGNAME");
		if (!username)
			username = "guest";
	}
	c_username = ft_strjoin_three(COLOR_WHITE, username, COLOR_RESET);
	return (c_username);
}

char	*get_current_dir(void)
{
	char	**cwd_split;
	char	*current_dir;

	current_dir = get_working_directory();
	cwd_split = ft_split(current_dir, '/');
	ft_free(current_dir);
	current_dir = cwd_split[ft_matrix_len(cwd_split) - 1];
	current_dir = ft_strjoin_three(COLOR_CYAN, current_dir, COLOR_RESET);
	ft_free_matrix(cwd_split);
	return (current_dir);
}

char	*format_prompt(t_prompt *prompt_data)
{
	char	*formatted_prompt;
	char	*prompt;
	char	*p_temp;

	prompt = ft_strjoin("[", prompt_data->user);
	p_temp = ft_strjoin(prompt, "@");
	free(prompt);
	prompt = ft_strjoin(p_temp, prompt_data->hostname);
	free(p_temp);
	p_temp = ft_strjoin(prompt, prompt_data->current_dir);
	free(prompt);
	formatted_prompt = ft_strjoin(p_temp, " ]$ ");
	free(p_temp);
	return (formatted_prompt);
}
