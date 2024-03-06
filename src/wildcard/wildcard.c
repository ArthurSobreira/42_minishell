/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:42:44 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/05 19:11:06 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	has_wildcard(char *str)
{
	while (*str)
	{
		if (*str == '*')
			return (TRUE);
		str++;
	}
	return (FALSE);
}

t_token	*find_wild(void)
{
	t_token	*current_tkn;

	current_tkn = get_core()->token_list;
	while (current_tkn)
	{
		if (has_wildcard(current_tkn->value))
		{
			return (current_tkn);
		}
		current_tkn = current_tkn->next;
	}
	return (NULL);
}

void	expand_wildcard(void)
{
	t_token	*tkn;
	char	*path;

	path = getcwd(NULL, 0);
	tkn = find_wild();
	free(path);
	if (tkn)
	{
		print_token(tkn);
		printf("path: %s\n", path);
	}
}
