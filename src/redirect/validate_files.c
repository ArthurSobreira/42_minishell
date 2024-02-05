/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:12:23 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/01 22:12:23 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	validate_io_files(t_token *token)
{
	t_token		*current_tkn;

	current_tkn = token;
	while (current)
	{
		if (current_tkn->type == TOKEN_REDIRECT || 
				current_tkn->type == TOKEN_APPEND)
		{
			if (current_tkn->next == NULL || 
				current_tkn->next->type != TOKEN_WORD)
				ft_error("syntax error near unexpected token `newline'\n", 
					SYNTAX_ERROR);
		}
		else if (current_tkn->type == TOKEN_REDIRECT_REVERSE)
		{
			if (!check_file_existence(current_tkn->next->value) || 
				!check_file_permissions(current_tkn->next->value))
				ft_error("no such file or directory\n", EXIT_FAILURE);
		}
		current_tkn = current_tkn->next;
	}
}

void	handle_redirects(void)
{
	t_minishell	*core;
	t_token		*current_tkn;

	core = get_core();
	current_tkn = core->token;
	validate_io_files(current_tkn);
	while (current_tkn)
	{
		if (current_tkn->type == TOKEN_REDIRECT)
			redirect_output(current_tkn);
		else if (current_tkn->type == TOKEN_REDIRECT_REVERSE)
			redirect_input(current_tkn);
		else if (current_tkn->type == TOKEN_APPEND)
			append_output(current_tkn);
		else if (current_tkn->type == TOKEN_HERE_DOC)
			here_doc(current_tkn);
		current_tkn = current_tkn->next;
	}
}
