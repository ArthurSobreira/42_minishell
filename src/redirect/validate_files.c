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

t_bool	validate_input_file(t_token *current_tkn, size_t index)
{
	if (current_tkn->type == TOKEN_REDIRECT_REVERSE)
	{
		if (!check_file_exists(current_tkn->next->value))
		{
			ft_file_error(current_tkn->next->value, \
				"No such file or directory\n", EXIT_FAILURE, index);
			return (FALSE);
		}
		else if (!check_file_readable(current_tkn->next->value))
		{
			ft_file_error(current_tkn->next->value, "Permission denied\n",
				PERMISSION_ERROR, index);
			return (FALSE);
		}
	}
	return (TRUE);
}

t_bool	validate_output_file(t_token *current_tkn, size_t index)
{
	if (check_file_exists(current_tkn->next->value))
	{
		if (!check_file_writable(current_tkn->next->value))
		{
			ft_file_error(current_tkn->next->value, "Permission denied\n",
				PERMISSION_ERROR, index);
			return (FALSE);
		}
	}
	else if (check_file_executable(current_tkn->next->value))
	{
		ft_file_error(current_tkn->next->value, "Is a directory\n",
			EXIT_FAILURE, index);
		return (FALSE);
	}
	return (TRUE);
}

void	open_in_files(t_redir_in *redir_in)
{
	char	*file_name;

	file_name = NULL;
	if (redir_in->r_type == TOKEN_HERE_DOC)
	{
		redir_in->here_doc = TRUE;
		redir_in->fd_in = open(HERE_DOC_FILE, \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else if (redir_in->r_type == TOKEN_REDIRECT_REVERSE)
	{
		file_name = redir_in->file_name;
		redir_in->here_doc = FALSE;
		redir_in->fd_in = open(file_name, O_RDONLY);
	}
}

void	open_create_out_files(t_redir_out *redir_out)
{
	char	*file_name;

	file_name = redir_out->file_name;
	if (redir_out->r_type == TOKEN_APPEND)
	{
		redir_out->fd_out = open(file_name, O_WRONLY | \
					O_CREAT | O_APPEND, 0644);
	}
	else if (redir_out->r_type == TOKEN_REDIRECT)
	{
		redir_out->fd_out = open(file_name, O_WRONLY | \
					O_CREAT | O_TRUNC, 0644);
	}
}
