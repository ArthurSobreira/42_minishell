/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:11:36 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/06 15:41:24 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir_in	*create_redir_in(t_tkn_type r_type, char *file_name)
{
	t_redir_in	*new_redir;

	new_redir = malloc(sizeof(t_redir_in));
	if (!new_redir)
		return (NULL);
	new_redir->r_type = r_type;
	new_redir->file_name = ft_strdup(file_name);
	new_redir->fd_in = -1;
	new_redir->here_doc = FALSE;
	new_redir->hd_limiter = NULL;
	new_redir->next = NULL;
	return (new_redir);
}

t_redir_out	*create_redir_out(t_tkn_type r_type, char *file_name)
{
	t_redir_out	*new_redir;

	new_redir = malloc(sizeof(t_redir_out));
	if (!new_redir)
		return (NULL);
	new_redir->r_type = r_type;
	new_redir->file_name = ft_strdup(file_name);
	new_redir->fd_out = -1;
	new_redir->next = NULL;
	return (new_redir);
}

t_redir_in	*find_last_redir_in(t_redir_in *redir)
{
	t_redir_in	*current_redir;

	current_redir = redir;
	while (current_redir->next != NULL)
		current_redir = current_redir->next;
	return (current_redir);
}

t_redir_out	*find_last_redir_out(t_redir_out *redir)
{
	t_redir_out	*current_redir;

	current_redir = redir;
	while (current_redir->next != NULL)
		current_redir = current_redir->next;
	return (current_redir);
}
