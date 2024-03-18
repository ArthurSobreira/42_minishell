/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:20:22 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/10 19:16:57 by arsobrei         ###   ########.fr       */
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

int	where_is_dollar(char *str, t_bool *in_quote, int i)
{
	*in_quote = FALSE;
	while (str[i])
	{
		if (str[i] == '\"')
		{
			get_core()->pos = i;
			*in_quote = !*in_quote;
		}
		if (str[i] == '\'' && !*in_quote)
			skip_squote(str, &i);
		if (str[i] && str[i] == '$' && str[i + 1] && (ft_isalnum(str[i + 1])
				|| str[i + 1] == '_' || str[i + 1] == '?' || str[i + 1] == '$'))
			return (i);
		if (!str[i])
			break ;
		i++;
	}
	return (ft_strlen(str));
}

char	*get_var_value(char *var_name)
{
	t_var	*var;
	char	c[2];

	var = get_core()->env_vars;
	c[0] = '\t';
	c[1] = '\0';
	while (var)
	{
		if (ft_strcmp(var->key, var_name) == 0)
			return (ft_strdup(var->value));
		var = var->next;
	}
	return (ft_strdup(c));
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
				remove_quote(token->value);
				token = token->next;
				continue ;
			}
			token->value = look_for_variable(token->value);
			token->value = ft_replace_true(token->value, "\n", "$");
			token->value = ft_replace_true(token->value, "\t", "");
			remove_quote(token->value);
		}
		token = token->next;
	}
}
