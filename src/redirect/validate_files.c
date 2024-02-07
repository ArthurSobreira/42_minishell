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

void	validate_input_file(t_token *current_tkn)
{
	if (current_tkn->next == NULL || 
		current_tkn->next->type != TOKEN_WORD)
		ft_error("syntax error near unexpected token `newline'\n", 
			SYNTAX_ERROR);
	if (current_tkn->type == TOKEN_REDIRECT_REVERSE)
	{
		if (!check_file_exists(current_tkn->next->value))
			ft_error("no such file or directory\n", EXIT_FAILURE);
		else if (!check_file_readable(current_tkn->next->value))
			ft_error("permission denied\n", PERMISSION_ERROR);
	}
}

void	validate_output_file(t_token *current_tkn)
{
	if (current_tkn->next == NULL || 
		current_tkn->next->type != TOKEN_WORD)
		ft_error("syntax error near unexpected token `newline'\n", 
			SYNTAX_ERROR);
	if (check_file_executable(current_tkn->next->value))
		ft_error("is a directory\n", EXIT_FAILURE);
	if (check_file_exists(current_tkn->next->value))
	{
		if (!check_file_writable(current_tkn->next->value))
			ft_error("permission denied\n", PERMISSION_ERROR);
	}
}

void	open_create_out_files(t_redir_out *redir_out)
{
	char	*file_name;

	file_name = redir_out->file_name;
	if (redir_out->r_type == TOKEN_APPEND)
	{
		redir_out->fd_out = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (redir_out->fd_out < 0)
			ft_error("cannot open the file\n", EXIT_FAILURE);
	}
	else if (redir_out->r_type == TOKEN_REDIRECT)
	{
		redir_out->fd_out = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (redir_out->fd_out < 0)
			ft_error("cannot open the file\n", EXIT_FAILURE);
	}
}
