/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:23:02 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/10 19:31:42 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*tratament_quotes(char *str, char *var_name, char *var_value)
{
	t_replace	rp;
	int			i;

	i = get_core()->pos;
	rp.start = 0;
	while (str[i])
	{
		if (str[i] == '\"')
		{
			rp.start = i;
			i++;
			while (str[i] && str[i] != '\"')
				i++;
			rp.end = i;
			str = ft_replace_small(str, var_name, var_value, &rp);
			break ;
		}
		i++;
	}
	return (str);
}

char	*look_for_variable(char *str)
{
	int		i;
	t_bool	in_quote;

	i = where_is_dollar(str, &in_quote, 0);
	while (i < (int)ft_strlen(str))
	{
		str = process_variable(str, i, &in_quote);
		if (str[i] == '$')
			i++;
		i = where_is_dollar(str, &in_quote, i);
	}
	return (str);
}

char	*process_variable(char *str, int i, t_bool *in_quote)
{
	int		j;
	char	*var_name;
	char	*var_value;

	j = i + 1;
	while (str[j] && (ft_isalnum(str[j]) || str[j] == '_'))
		j++;
	if (str[j - 1] == '$' && str[j] == '$')
		j++;
	if (str[j - 1] == '$' && str[j] == '?')
		j++;
	var_name = ft_substr(str, i, j - i);
	var_value = get_var_value(var_name + 1);
	var_value = handle_var_value(var_name, var_value);
	str = replace_or_treat_quotes(str, var_name, var_value, in_quote);
	free(var_name);
	free(var_value);
	return (str);
}

char	*handle_var_value(char *var_name, char *var_value)
{
	if (var_name[1] == '?' && var_name[0] == '$')
	{
		free(var_value);
		var_value = ft_itoa(get_core()->exit_status);
	}
	if (var_name[1] == '$' && var_name[0] == '$')
	{
		free(var_value);
		var_value = ft_strdup("\n");
	}
	return (var_value);
}

char	*replace_or_treat_quotes(char *str, char *var_name, char *var_value,
		t_bool *in_quote)
{
	if (!(*in_quote))
		str = ft_replace_quotes(str, var_name, var_value);
	else
		str = tratament_quotes(str, var_name, var_value);
	return (str);
}
