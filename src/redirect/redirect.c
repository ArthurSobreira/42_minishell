/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:19:30 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/06 16:19:30 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_redir_out(t_redir_out *redir_list)
{
	t_redir_out *current_redir;

	current_redir = redir_list;
	while (current_redir)
	{
		printf("\nr_type: %d\n", current_redir->r_type);
		printf("redir_out: %s\n", current_redir->file_name);
		printf("fd_out: %d\n\n", current_redir->fd_out);
		current_redir = current_redir->next;
	}
}

void	handle_redirects(void)
{
	t_minishell	*core;
	t_token 	*current_tkn;
	t_token		*next_tkn;
	t_redir_in	*redir_in;
	t_redir_out	*redir_out;

	core = get_core();
	validate_io_files(core->token_list);
	current_tkn = core->token_list;
	redir_in = NULL;
	redir_out = NULL;
	while (current_tkn)
	{
		next_tkn = current_tkn->next;
		if (current_tkn->type == TOKEN_REDIRECT ||
			current_tkn->type == TOKEN_APPEND ||
			current_tkn->type == TOKEN_REDIRECT_REVERSE ||
			current_tkn->type == TOKEN_HERE_DOC)
		{
			if (current_tkn->type == TOKEN_REDIRECT ||
				current_tkn->type == TOKEN_APPEND)
			{
				handle_redir_out(&redir_out, current_tkn);
				// if (current_tkn->prev)
				// 	current_tkn->prev->next = current_tkn->next->next;
				// else
				// 	core->token_list = current_tkn->next->next;
				// if (current_tkn->next->next)
				// 	current_tkn->next->next->prev = current_tkn->prev;
				// free(current_tkn->next);
				// free(current_tkn);
				// remove_redir_token(current_tkn->next);
				// remove_redir_token(current_tkn);
				next_tkn = current_tkn->next->next;
				remove_redir_token(&core->token_list, current_tkn->next);
				remove_redir_token(&core->token_list, current_tkn);
			}
		}
		current_tkn = next_tkn;
	}
	print_redir_out(redir_out);
	print_token(core->token_list);
	ft_clear_redir_out(&redir_out);
}

void	remove_redir_token(t_token **token_list, t_token *target_tkn)
{
	t_token *current_tkn;

	current_tkn = *token_list;
	while (current_tkn)
	{
		if (current_tkn == target_tkn)
		{
			if (current_tkn->prev)
				current_tkn->prev->next = current_tkn->next;
			else
				*token_list = current_tkn->next;
			if (current_tkn->next)
				current_tkn->next->prev = current_tkn->prev;
			if (current_tkn->type == TOKEN_APPEND)
				ft_free(current_tkn->value);
			ft_free(current_tkn);
			break ;
		}
		current_tkn = current_tkn->next;
	}
}

void	handle_redir_out(t_redir_out **redir_list, t_token *current_tkn)
{
	t_token *current_cpy;
	t_token *next_tkn;
	t_redir_out *redir_out;

	current_cpy = current_tkn;
	next_tkn = current_tkn->next;
	redir_out = create_redir_out(current_cpy->type, next_tkn->value);
	if (redir_out != NULL)
	{
		if (*redir_list == NULL)
			*redir_list = redir_out;
		else
			find_last_redir_out(*redir_list)->next = redir_out;
	}
}
