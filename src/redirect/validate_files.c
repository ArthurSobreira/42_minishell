/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:18:16 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/05 19:18:16 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	validate_io_files(t_token *token_list)
{
	t_token		*current_tkn;

	current_tkn = token_list;
	while (current_tkn)
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
			if (!check_file_exists(current_tkn->next->value) || 
				!check_file_readable(current_tkn->next->value))
				ft_error("no such file or directory\n", EXIT_FAILURE);
		}
		current_tkn = current_tkn->next;
	}
}

t_bool	check_file_exists(char *file_name)
{
	if (access(file_name, F_OK) == -1)
	{
		ft_error("no such file or directory\n", EXIT_FAILURE);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	check_file_readable(char *file_name)
{
	if (access(file_name, R_OK) == -1)
	{
		ft_error("permission denied\n", PERMISSION_ERROR);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	check_file_writable(char *file_name)
{
	if (access(file_name, W_OK) == -1)
	{
		ft_error("permission denied\n", PERMISSION_ERROR);
		return (FALSE);
	}
	return (TRUE);
}
