/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:20:22 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/05 19:49:06 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_variables(char *str, t_var *env, t_tkn_type type)
{
	char	*new_str;

	while (*str && *str != '\'')
	{
		if (*str == '$')
		{
			if (type == TOKEN_QUOTE)
				new_str = ft_substr(++str, 0, ft_strchr(str, ' ') - str);
			else if (type == TOKEN_WORD)
				new_str = ft_strdup(++str);
			return (new_str);
		}
		str++;
	}
	return (NULL);
}
