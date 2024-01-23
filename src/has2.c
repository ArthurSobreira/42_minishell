/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:23:25 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/23 12:25:23 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	has_here_doc(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '<' && str[i + 1] == '<')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	issquote(char str)
{
	if (str == '\'')
		return (TRUE);
	return (FALSE);
}

t_bool	isdquote(char str)
{
	if (str == '\"')
		return (TRUE);
	return (FALSE);
}