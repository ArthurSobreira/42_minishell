/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:22:00 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/23 12:24:34 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	has_pipe(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	has_redirection(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>' || str[i] == '<')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	has_background(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '&')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	has_and(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '&' && str[i + 1] == '&')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	has_or(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|' && str[i + 1] == '|')
			return (TRUE);
		i++;
	}
	return (FALSE);
}
