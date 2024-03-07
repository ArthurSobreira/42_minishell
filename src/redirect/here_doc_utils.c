/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:49:33 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/07 11:52:30 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_for_expansions(t_var *env_vars, char *line)
{
	char	expanded_line[MAX_VAR_LEN];
	char	*result_var;
	size_t	l_index;
	size_t	e_index;
	t_var	*temp_env;

	if (ft_strchr(line, '$') == NULL)
		return (line);
	l_index = 0;
	e_index = 0;
	temp_env = env_vars;
	ft_bzero(expanded_line, MAX_VAR_LEN);
	while (line[l_index])
	{
		if (line[l_index] == '$')
		{
			result_var = get_var(temp_env, line, &l_index);
			ft_strlcat(expanded_line, result_var, MAX_VAR_LEN);
			e_index += ft_strlen(result_var);
			free(result_var);
		}
		else
			expanded_line[e_index++] = line[l_index++];
	}
	return (ft_strdup(expanded_line));
}

char	*get_var(t_var *env_vars, char *line, size_t *l_index)
{
	size_t	temp_var_len;
	char	*temp_var;
	char	*var;

	*l_index += 1;
	temp_var_len = get_var_len(line, *l_index);
	temp_var = ft_substr(line, *l_index, temp_var_len);
	while (env_vars)
	{
		if (!ft_strcmp(temp_var, "?") || \
			!ft_strcmp(env_vars->key, temp_var))
		{
			if (!ft_strcmp(temp_var, "?"))
				var = ft_itoa(get_core()->exit_status);
			else
				var = ft_strdup(env_vars->value);
			free(temp_var);
			*l_index += temp_var_len;
			return (var);
		}
		env_vars = env_vars->next;
	}
	free(temp_var);
	*l_index += temp_var_len;
	return (ft_strdup(""));
}

size_t	get_var_len(char *line, size_t l_index)
{
	size_t	len;

	len = 0;
	while (line[l_index + len] && \
			line[l_index + len] != ' ' && \
			line[l_index + len] != '$' && \
			line[l_index + len] != '\'' && \
			line[l_index + len] != '\"')
		len++;
	return (len);
}
