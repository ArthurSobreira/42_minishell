/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:33:37 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/12 22:39:44 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	capture_heredoc(t_token *current_tkn)
{
	t_token		*current_cpy;
	char		*hd_limiter;
	int			here_doc_fd;

	current_cpy = current_tkn;
	while (current_cpy)
	{
		if ((current_cpy->type == TOKEN_HERE_DOC) && \
			(current_cpy->next->type == TOKEN_WORD))
		{
			here_doc_fd = open(HERE_DOC_FILE, \
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
			hd_limiter = current_cpy->next->value;
			here_doc_loop(hd_limiter, here_doc_fd);
		}
		current_cpy = current_cpy->next;
	}
}

void	here_doc_loop(char *hd_limiter, int here_doc_fd)
{
	char	*line;

	while (TRUE)
	{
		line = readline("> ");
		if (!ft_strcmp(line, hd_limiter))
		{
			free(line);
			close(here_doc_fd);
			break ;
		}
		ft_putendl_fd(line, here_doc_fd);
		free(line);
	}
}
