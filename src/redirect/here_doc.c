/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:33:37 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/07 14:13:07 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	capture_heredoc(void)
{
	t_token	*current_tkn;
	char	*hd_limiter;
	int		here_doc_fd;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	current_tkn = get_core()->token_list;
	while (current_tkn)
	{
		if ((current_tkn->type == TOKEN_HERE_DOC) && \
			(current_tkn->next->type == TOKEN_WORD))
		{
			here_doc_fd = open(HERE_DOC_FILE,
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
			hd_limiter = current_tkn->next->value;
			if (!get_core()->here_doc_flag)
				here_doc_child(hd_limiter, here_doc_fd);
		}
		current_tkn = current_tkn->next;
	}
}

void	here_doc_child(char *hd_limiter, int here_doc_fd)
{
	t_var	*env_vars;
	pid_t	pid;

	env_vars = get_core()->env_vars;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, ctrl_c_here_doc);
		here_doc_loop(hd_limiter, here_doc_fd, env_vars);
	}
	else
		wait_here_doc_child(pid);
}

void	here_doc_loop(char *hd_limiter, int here_doc_fd, t_var *env_vars)
{
	char	*line;

	while (TRUE)
	{
		line = readline("> ");
		if (!line)
		{
			ft_printf_fd(2, "minishell: %s (wanted `%s')\n", HD_ERROR,
				hd_limiter);
			free(line);
			break ;
		}
		else if (!ft_strcmp(line, hd_limiter))
		{
			free(line);
			break ;
		}
		if (ft_strcmp(line, "$"))
			line = search_for_expansions(env_vars, line);
		ft_putendl_fd(line, here_doc_fd);
		free(line);
	}
	close(here_doc_fd);
	clear_child(get_core());
}

void	wait_here_doc_child(pid_t pid)
{
	int		status_addr;
	int		status;

	waitpid(pid, &status_addr, 0);
	if (WIFEXITED(status_addr))
	{
		status = WEXITSTATUS(status_addr);
		if (status == 130)
		{
			if (get_core()->exit_status != 130)
				get_core()->here_doc_flag = TRUE;
			get_core()->exit_status = status;
		}
		else
			get_core()->exit_status = EXIT_SUCCESS;
	}
}
