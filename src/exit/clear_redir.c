/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:36:49 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/12 22:36:49 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_unnecessary_redir_out(t_redir_out **redir_out)
{
	t_redir_out	*tmp_out;

	if (*redir_out == NULL)
		return ;
	while ((*redir_out)->next)
	{
		tmp_out = (*redir_out)->next;
		if ((*redir_out != NULL) && \
			((*redir_out)->r_type == TOKEN_APPEND || \
			(*redir_out)->r_type == TOKEN_REDIRECT))
		{
			close((*redir_out)->fd_out);
			ft_free((*redir_out)->file_name);
			ft_free(*redir_out);
			(*redir_out) = tmp_out;
		}
	}
}

void	remove_unnecessary_redir_in(t_redir_in **redir_in)
{
	t_redir_in	*tmp_in;

	if (*redir_in == NULL)
		return ;
	while ((*redir_in)->next)
	{
		tmp_in = (*redir_in)->next;
		if ((*redir_in)->here_doc == FALSE)
		{
			close((*redir_in)->fd_in);
			ft_free((*redir_in)->file_name);
			ft_free(*redir_in);
		}
		else if ((*redir_in)->here_doc == TRUE)
		{
			close((*redir_in)->fd_in);
			unlink((*redir_in)->file_name);
			ft_free((*redir_in)->file_name);
			ft_free(*redir_in);
		}
		(*redir_in) = tmp_in;
	}
}

void	ft_clear_redir_in(t_redir_in **redir_in)
{
	t_redir_in	*tmp_in;

	if (*redir_in == NULL)
		return ;
	while (*redir_in)
	{
		tmp_in = (*redir_in)->next;
		close((*redir_in)->fd_in);
		ft_free((*redir_in)->file_name);
		ft_free(*redir_in);
		*redir_in = tmp_in;
	}
}

void	ft_clear_redir_out(t_redir_out **redir_out)
{
	t_redir_out	*tmp_out;

	if (*redir_out == NULL)
		return ;
	while (*redir_out)
	{
		tmp_out = (*redir_out)->next;
		close((*redir_out)->fd_out);
		ft_free((*redir_out)->file_name);
		ft_free(*redir_out);
		*redir_out = tmp_out;
	}
}
