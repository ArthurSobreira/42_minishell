/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:33:37 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/07 16:35:31 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_here_doc(t_redir_in **redir_list, t_token *current_tkn)
{
	// t_token *current_cpy;
	// t_token *next_tkn;
	// t_redir_in *redir_in;

	// current_cpy = current_tkn;
	// next_tkn = current_tkn->next;
	// redir_in = create_redir_in(current_cpy->type, next_tkn->value);
	// if (redir_in != NULL)
	// {
	// 	if (*redir_list == NULL)
	// 		*redir_list = redir_in;
	// 	else
	// 		find_last_redir_in(*redir_list)->next = redir_in;
	// }
	(void)redir_list;
	(void)current_tkn;
}
