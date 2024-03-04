/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:33:37 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/04 10:30:48 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	capture_heredoc(void)
// {
// 	t_token	*current_tkn;
// 	char	*hd_limiter;
// 	pid_t	pid;
// 	int		status;

// 	signal(SIGINT, SIG_IGN);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		signal(SIGINT, ctrl_c_here_doc);
// 		signal(SIGQUIT, SIG_IGN);
// 		current_tkn = get_core()->token_list;
// 		while (current_tkn)
// 		{
// 			if ((current_tkn->type == TOKEN_HERE_DOC) &&
// 				(current_tkn->next->type == TOKEN_WORD))
// 			{
// 				get_core()->here_doc_fd = open(HERE_DOC_FILE,
// 						O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 				hd_limiter = current_tkn->next->value;
// 				here_doc_loop(hd_limiter, get_core()->here_doc_fd);
// 			}
// 			current_tkn = current_tkn->next;
// 		}
// 		exit_shell(NULL);
// 	}
// 	else
// 	{
// 		waitpid(pid, &status, 0);
// 		signal(SIGINT, ctrl_c);
// 		if (WIFSIGNALED(status))
// 			get_core()->exit_status = 128 + WTERMSIG(status);
// 	}
// }

void handle_child_process() {
    signal(SIGINT, ctrl_c_here_doc);
    signal(SIGQUIT, SIG_IGN);
    t_token *current_tkn = get_core()->token_list;
    while (current_tkn) {
        if ((current_tkn->type == TOKEN_HERE_DOC) && (current_tkn->next->type == TOKEN_WORD)) {
            get_core()->here_doc_fd = open(HERE_DOC_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            char *hd_limiter = current_tkn->next->value;
            here_doc_loop(hd_limiter, get_core()->here_doc_fd);
        }
        current_tkn = current_tkn->next;
    }
    exit_shell(NULL);
}

void handle_parent_process(pid_t pid) {
    int status;
    waitpid(pid, &status, 0);
    signal(SIGINT, ctrl_c);
    if (WIFSIGNALED(status)) {
        get_core()->exit_status = 128 + WTERMSIG(status);
    }
}

void capture_heredoc() {
    signal(SIGINT, SIG_IGN);
    pid_t pid = fork();
    if (pid == 0) {
        handle_child_process();
    } else {
        handle_parent_process(pid);
    }
}


void	here_doc_loop(char *hd_limiter, int here_doc_fd)
{
	t_var	*env_vars;
	char	*line;

	env_vars = get_core()->env_vars;
	while (TRUE)
	{
		line = readline("> ");
		if (!line)
		{
			ft_printf_fd(2, "minishell: %s (wanted `%s')\n", HD_ERROR,
					hd_limiter);
			close(here_doc_fd);
			exit_shell(NULL);
		}
		else if (!ft_strcmp(line, hd_limiter))
		{
			free(line);
			close(here_doc_fd);
			break ;
		}
		if (ft_strcmp(line, "$"))
			line = search_for_expansions(env_vars, line);
		ft_putendl_fd(line, here_doc_fd);
		free(line);
	}
}

char	*search_for_expansions(t_var *env_vars, char *line)
{
	char	expanded_line[MAX_VAR_LEN];
	char	*result_var;
	size_t	l_index;
	size_t	e_index;
	t_var	*temp_env;

	if (ft_strchr(line, '$') == NULL)
		return (line);
	l_index = 0;
	e_index = 0;
	temp_env = env_vars;
	ft_bzero(expanded_line, MAX_VAR_LEN);
	while (line[l_index])
	{
		if (line[l_index] == '$')
		{
			result_var = get_var(temp_env, line, &l_index);
			ft_strlcat(expanded_line, result_var, MAX_VAR_LEN);
			e_index += ft_strlen(result_var);
			free(result_var);
		}
		else
			expanded_line[e_index++] = line[l_index++];
	}
	return (ft_strdup(expanded_line));
}

char	*get_var(t_var *env_vars, char *line, size_t *l_index)
{
	size_t	temp_var_len;
	char	*temp_var;
	char	*var;

	*l_index += 1;
	temp_var_len = get_var_len(line, *l_index);
	temp_var = ft_substr(line, *l_index, temp_var_len);
	while (env_vars)
	{
		if (!ft_strcmp(temp_var, "?") ||
			!ft_strcmp(env_vars->key, temp_var))
		{
			if (!ft_strcmp(temp_var, "?"))
				var = ft_itoa(get_core()->exit_status);
			else
				var = ft_strdup(env_vars->value);
			free(temp_var);
			*l_index += temp_var_len;
			return (var);
		}
		env_vars = env_vars->next;
	}
	free(temp_var);
	*l_index += temp_var_len;
	return (ft_strdup(""));
}

size_t	get_var_len(char *line, size_t l_index)
{
	size_t	len;

	len = 0;
	while (line[l_index + len] &&
			line[l_index + len] != ' ' &&
			line[l_index + len] != '$')
		len++;
	return (len);
}
