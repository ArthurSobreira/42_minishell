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

void	handle_redirects(void)
{
	t_token 	*current_tkn;
	t_token		*next_tkn;
	t_redir_in	*redir_in;
	t_redir_out	*redir_out;

	current_tkn = get_core()->token_list;
	redir_in = NULL;
	redir_out = NULL;
	while (current_tkn)
	{
		next_tkn = current_tkn->next;
		if (is_redir_token(current_tkn) && (next_tkn != NULL))
		{
			if (current_tkn->type == TOKEN_HERE_DOC)
				handle_here_doc(&redir_in, current_tkn);
			if (current_tkn->type == TOKEN_REDIRECT_REVERSE)
				handle_redir_in(&redir_in, current_tkn);
			else if (current_tkn->type == TOKEN_REDIRECT || 
				current_tkn->type == TOKEN_APPEND)
				handle_redir_out(&redir_out, current_tkn);
			next_tkn = current_tkn->next->next;
			remove_redir_token(&get_core()->token_list, current_tkn->next);
			remove_redir_token(&get_core()->token_list, current_tkn);
		}
		current_tkn = next_tkn;
	}

	// Remove later
	printf("\n=====Redirect out list =====\n");
	print_redir_out(redir_out);

	remove_unnecessary_redir_out(&redir_out);
	
	// printf("\n=====Redirect in  list =====\n");
	// print_redir_in(redir_in);
	print_token(get_core()->token_list);
	ft_clear_redir_out(&redir_out);
	ft_clear_redir_in(&redir_in);
}

void	remove_unnecessary_redir_out(t_redir_out **redir_out)
{
	t_redir_out	*tmp_out;

	if (*redir_out == NULL)
		return ;
	while ((*redir_out)->next)
	{
		tmp_out = (*redir_out)->next;
		if (*redir_out != NULL && ((*redir_out)->r_type == TOKEN_APPEND || 
			(*redir_out)->r_type == TOKEN_REDIRECT))
		{
			close((*redir_out)->fd_out);
			ft_free((*redir_out)->file_name);
			ft_free(*redir_out);
			(*redir_out) = tmp_out;
		}
	}
	printf("\n=====Redirect out list =====\n");
	print_redir_out(*redir_out);
}

void	handle_redir_out(t_redir_out **redir_list, t_token *current_tkn)
{
	t_token		*current_cpy;
	t_token 	*next_tkn;
	t_redir_out *redir_out;

	current_cpy = current_tkn;
	next_tkn = current_tkn->next;
	validate_output_file(current_cpy);
	redir_out = create_redir_out(current_cpy->type, next_tkn->value);
	if (redir_out != NULL)
	{
		if (*redir_list == NULL)
			*redir_list = redir_out;
		else
			find_last_redir_out(*redir_list)->next = redir_out;
	}
	open_create_out_files(redir_out);
}

void	handle_redir_in(t_redir_in **redir_list, t_token *current_tkn)
{
	t_token		*current_cpy;
	t_token		*next_tkn;
	t_redir_in	*redir_in;

	current_cpy = current_tkn;
	next_tkn = current_tkn->next;
	validate_input_file(current_cpy);
	redir_in = create_redir_in(current_cpy->type, next_tkn->value);
	if (redir_in != NULL)
	{
		if (*redir_list == NULL)
			*redir_list = redir_in;
		else
			find_last_redir_in(*redir_list)->next = redir_in;
	}
}
