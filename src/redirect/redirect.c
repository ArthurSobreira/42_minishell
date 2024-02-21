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

void	handle_redirects(t_cmd *cmd, size_t index)
{
	t_token		*current_tkn;
	t_token		*next_tkn;

	current_tkn = get_core()->token_list;
	if (current_tkn && current_tkn->type == TOKEN_PIPE)
		remove_token(&get_core()->token_list, current_tkn);
	current_tkn = get_core()->token_list;
	while (current_tkn && current_tkn->type != TOKEN_PIPE)
	{
		next_tkn = current_tkn->next;
		if (is_redir_token(current_tkn) && (next_tkn != NULL))
		{
			if (current_tkn->type == TOKEN_HERE_DOC)
				handle_here_doc(&cmd->redir_in, current_tkn, index);
			if (current_tkn->type == TOKEN_REDIRECT_REVERSE)
				handle_redir_in(&cmd->redir_in, current_tkn, index);
			else if (current_tkn->type == TOKEN_REDIRECT || \
				current_tkn->type == TOKEN_APPEND)
				handle_redir_out(&cmd->redir_out, current_tkn, index);
			next_tkn = current_tkn->next->next;
			remove_token(&get_core()->token_list, current_tkn->next);
			remove_token(&get_core()->token_list, current_tkn);
		}
		current_tkn = next_tkn;
	}
}

void	handle_here_doc(t_redir_in **redir_list, t_token *tkn, size_t index)
{
	t_token		*current_cpy;
	t_redir_in	*redir_in;

	current_cpy = tkn;
	if (get_core()->error_check.file_error[index])
	{
		ft_clear_redir_in(redir_list);
		return ;
	}
	redir_in = create_redir_in(current_cpy->type, HERE_DOC_FILE);
	if (redir_in != NULL)
	{
		if (*redir_list == NULL)
			*redir_list = redir_in;
		else
			find_last_redir_in(*redir_list)->next = redir_in;
		open_in_files(redir_in);
	}
}

void	handle_redir_in(t_redir_in **redir_list, t_token *tkn, size_t index)
{
	t_token		*current_cpy;
	t_token		*next_tkn;
	t_redir_in	*redir_in;

	current_cpy = tkn;
	next_tkn = tkn->next;
	if (!validate_input_file(current_cpy, index) || \
		get_core()->error_check.file_error[index])
	{
		ft_clear_redir_in(redir_list);
		return ;
	}
	redir_in = create_redir_in(current_cpy->type, next_tkn->value);
	if (redir_in != NULL)
	{
		if (*redir_list == NULL)
			*redir_list = redir_in;
		else
			find_last_redir_in(*redir_list)->next = redir_in;
		open_in_files(redir_in);
	}
}

void	handle_redir_out(t_redir_out **redir_list, t_token *tkn, size_t index)
{
	t_token		*current_cpy;
	t_token		*next_tkn;
	t_redir_out	*redir_out;

	current_cpy = tkn;
	next_tkn = tkn->next;
	if (!validate_output_file(current_cpy, index) || \
		get_core()->error_check.file_error[index])
	{
		ft_clear_redir_out(redir_list);
		return ;
	}
	redir_out = create_redir_out(current_cpy->type, next_tkn->value);
	if (redir_out != NULL)
	{
		if (*redir_list == NULL)
			*redir_list = redir_out;
		else
			find_last_redir_out(*redir_list)->next = redir_out;
		open_create_out_files(redir_out);
	}
}
