/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:20:22 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/21 17:13:02 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_squote(char *str, int *i)
{
	char	quote;

	quote = '\'';
	(*i)++;
	while (str[*i] && str[*i] != quote)
		(*i)++;
}

int	where_is_dollar(char *str, t_bool *in_quote)
{
	int	i;

	*in_quote = FALSE;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			*in_quote = !*in_quote;
		if (str[i] == '\'' && !*in_quote)
			skip_squote(str, &i);
		if (str[i] == '$' && str[i + 1] && (ft_isalnum(str[i + 1]) || str[i
					+ 1] == '_' || str[i + 1] == '?' || str[i + 1] == '$'))
			return (i);
		i++;
	}
	return (-1);
}

char	*get_var_value(char *var_name)
{
	t_var	*var;

	var = get_core()->env_vars;
	while (var)
	{
		if (ft_strcmp(var->key, var_name) == 0)
			return (ft_strdup(var->value));
		var = var->next;
	}
	return (NULL);
}

void	remove_quote(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\'')
		{
			ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
			while (*str != '\'')
				str++;
			ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
		}
		else if (*str == '\"')
		{
			ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
			while (*str != '\"')
				str++;
			ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
		}
		else
			str++;
	}
}

void	check_variables(void)
{
	t_token	*token;

	token = get_core()->token_list;
	while (token)
	{
		if (token->type == TOKEN_WORD)
		{
			if (token->prev && token->prev->type == TOKEN_HERE_DOC)
			{
				token = token->next;
				continue ;
			}
			token->value = look_for_variable(token->value);
			remove_quote(token->value);
			printf("token->value: [%s]\n", token->value);
		}
		token = token->next;
	}
}
