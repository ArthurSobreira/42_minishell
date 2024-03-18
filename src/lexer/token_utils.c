/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:18:16 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/10 17:19:14 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_token(t_token *token)
{
	if (token)
	{
		free(token->value);
		free(token);
	}
}

size_t	count_tokens(t_token *token)
{
	size_t	count;

	count = 0;
	while (token->next)
	{
		count++;
		token = token->next;
	}
	return (count);
}

void	free_token_wildcard(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		tmp = token->next;
		free(token->value);
		free(token);
		token = tmp;
	}
}
