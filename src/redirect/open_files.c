/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:39:38 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/08 16:39:38 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_in_files(t_redir_in *redir_in)
{
	char	*file_name;

	file_name = redir_in->file_name;
	if (redir_in->r_type == TOKEN_REDIRECT_REVERSE)
	{
		redir_in->here_doc = FALSE;
		redir_in->hd_limiter = NULL;
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
