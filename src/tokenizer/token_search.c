/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:01:04 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/31 18:26:26 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	searsh_bugs(void)
{
	t_minishell	*core;
	t_token		*tmp;

	core = get_core();
	tmp = core->token_list;
	while (tmp)
	{
		if (tmp->type == TOKEN_AND)
			ft_error("syntax error: command not found", 127);
		else if (tmp->type == TOKEN_OR)
			ft_error("syntax error: command not found", 127);
		else if (tmp->type == TOKEN_SEMICOLON)
			ft_error("syntax error: command not found", 127);
		else if (tmp->type == TOKEN_BACKGROUND)
			ft_error("syntax error: command not found", 127);
		tmp = tmp->next;
	}
}
