/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_coisas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:39:32 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/12 16:30:16 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		printf("--------------------\n");
		printf("type: %d\n", tmp->type);
		printf("value: %s\n", tmp->value);
		printf("--------------------\n");
		tmp = tmp->next;
	}
}

void	print_redir_out(t_redir_out *redir_list)
{
	t_redir_out	*current_redir;

	current_redir = redir_list;
	while (current_redir)
	{
		printf("\nr_type: %d\n", current_redir->r_type);
		printf("redir_out: %s\n", current_redir->file_name);
		printf("fd_out: %d\n\n", current_redir->fd_out);
		current_redir = current_redir->next;
	}
}

void	print_redir_in(t_redir_in *redir_list)
{
	t_redir_in	*current_redir;

	current_redir = redir_list;
	while (current_redir)
	{
		printf("\nr_type: %d\n", current_redir->r_type);
		if (current_redir->here_doc)
			printf("has here_doc\n");
		else
			printf("no here_doc\n");
		printf("redir_in: %s\n", current_redir->file_name);
		printf("fd_in: %d\n\n", current_redir->fd_in);
		if (current_redir->hd_limiter)
			printf("hd_limiter: %s\n", current_redir->hd_limiter);
		current_redir = current_redir->next;
	}
}
