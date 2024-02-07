/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:20:22 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/07 15:36:00 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	find_var(char *str)
{
	t_var	*temp;

	temp = get_core()->env_vars;
	while (temp)
	{
		if (!ft_strcmp(temp->key, str))
		{
			printf("%s\n", temp->value);
			return ;
		}
		temp = temp->next;
	}
}

// void	look_for_variables(void)
// {
// 	t_token	*token;

// 	token = get_core()->token_list;
// 	while (token)
// 	{
// 		if ((token->type == TOKEN_WORD || token->type == TOKEN_DQUOTE))

// 		}
// 		token = token->next;
// 	}
// }
