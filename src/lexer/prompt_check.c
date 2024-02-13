/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 08:56:05 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/12 15:28:26 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	check_close_quotes(void)
{
	char	*str;
	int		i;

	str = get_core()->input;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			skip_quotes(str, &i);
			if (str[i] == '\0')
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_bool	check_forbidden_and(void)
{
	char	*str;
	int		i;

	str = get_core()->input;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			skip_quotes(str, &i);
		if (str[i] == '&' && str[i + 1] == '&')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	check_forbidden_or(void)
{
	char	*str;
	int		i;

	str = get_core()->input;
	i = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] == '\'' || str[i] == '\"')
			skip_quotes(str, &i);
		if (str[i] == '|' && str[i + 1] == '|')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	check_forbidden_semicolon(void)
{
	char	*str;
	int		i;

	str = get_core()->input;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			skip_quotes(str, &i);
		if (str[i] == ';')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	check_forbidden_background(void)
{
	char	*str;
	int		i;
	char	quote;

	str = get_core()->input;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			quote = str[i];
			i++;
			while (str[i] && str[i] != quote)
				i++;
		}
		if (str[i] == '&')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
