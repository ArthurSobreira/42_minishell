/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:20:22 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/14 17:29:54 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip(char *str, int *i)
{
	char	quote;

	quote = '\'';
	(*i)++;
	while (str[*i] && str[*i] != quote)
		(*i)++;
	if (str[*i] == quote && str[*i])
		(*i)++;
}

int	where_is_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			skip(str, &i);
		if (str[i] == '$')
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

char	*look_for_variable(char *str)
{
	int		i;
	int		j;
	char	*var_name;
	char	*var_value;

	i = where_is_dollar(str);
	while (i != -1)
	{
		j = i + 1;
		str = ft_replace_quotes(str + j, "{", "");
		str = ft_replace_quotes(str + j, "}", "");
		while (str[j] && !ft_isspace(str[j]) && str[j] != '\"' && str[j] != '\''
			&& str[j] != '$')
			j++;
		var_name = ft_substr(str, i, j - i);
		var_value = get_var_value(var_name + 1);
		if (!var_value && (var_name[1] != '?' || var_name[0] != '$'))
			var_value = ft_strdup("");
		str = ft_replace_quotes(str, var_name, var_value);
		str = ft_replace_quotes(str, "\"", "");
		str = ft_replace_quotes(str, "\'", "");
		free(var_name);
		free(var_value);
		printf("str: %s\n", str);
		i = where_is_dollar(str + i);
		printf("i: %d\n", i);
	}
	return (str);
}

void	check_variables(void)
{
	t_token	*token;

	token = get_core()->token_list;
	while (token)
	{
		if (token->type == TOKEN_WORD && ft_strlen(token->value) > 2)
		{
			if (token->prev && token->prev->type == TOKEN_HERE_DOC)
			{
				token = token->next;
				continue ;
			}
			token->value = look_for_variable(token->value);
			printf("token->value: %s\n", token->value);
		}
		token = token->next;
	}
}
