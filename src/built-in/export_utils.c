/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:51:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/26 14:53:15 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_ordened_values(char *key)
{
	t_var	*tmp;

	tmp = get_core()->env_vars;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
		{
			if (tmp->value)
				printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
			else
				printf("declare -x %s\n", tmp->key);
			return ;
		}
		tmp = tmp->next;
	}
}

t_bool	is_bigger(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] > s2[i])
		return (TRUE);
	return (FALSE);
}

char	*return_key(char *str)
{
	size_t	i;
	char	*key;

	i = 0;
	if (str[i] && str[i] != '=')
		i++;
	else
		return (NULL);
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '\0')
		return (ft_strdup(str));
	key = ft_calloc(i + 1, sizeof(char));
	if (!key)
		ft_error("export: malloc failed", 1);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		key[i] = str[i];
		i++;
	}
	return (key);
}

char	*return_value(char *str)
{
	size_t	i;
	size_t	j;
	char	*value;

	i = 0;
	if (ft_strchr(str, '=') == NULL)
		return (NULL);
	while (str[i] && str[i] != '=')
		i++;
	i++;
	j = i;
	while (str[j])
		j++;
	value = ft_calloc(j - i + 1, sizeof(char));
	if (!value)
		ft_error("export: malloc failed", 1);
	j = 0;
	while (str[i])
		value[j++] = str[i++];
	return (value);
}

void	add_end_var(t_var **var, t_var *new_var)
{
	t_var	*tmp;

	if (!*var)
	{
		*var = new_var;
		return ;
	}
	tmp = *var;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_var;
}
