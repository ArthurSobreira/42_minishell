/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:53 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/23 18:25:38 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	**ft_insert_str(char **arr, char *str, size_t index)
{
	size_t	i;
	size_t	len;
	char	**new_arr;

	len = ft_matrix_len(arr);
	new_arr = ft_calloc(len + 2, sizeof(char *));
	if (!new_arr)
		ft_error("export: malloc failed", 1);
	i = 0;
	while (i < index)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[i] = str;
	i++;
	while (arr[i - 1])
	{
		new_arr[i] = arr[i - 1];
		i++;
	}
	free(arr);
	return (new_arr);
}

void	get_value(char *key)
{
	t_var	*tmp;

	tmp = get_core()->env_vars;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
		{
			printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
			return ;
		}
		tmp = tmp->next;
	}
}

void	insert_sort(char **arr)
{
	int		i;
	int		j;
	char	**ordened;

	i = 1;
	ordened = ft_calloc(get_core()->env_vars_size + 1, sizeof(char *));
	if (!ordened)
		ft_error("export: malloc failed", 1);
	ordened[0] = arr[0];
	while (i < get_core()->env_vars_size)
	{
		j = 0;
		while (ordened[j] && is_bigger(arr[i], ordened[j]))
			j++;
		ordened = ft_insert_str(ordened, arr[i], j);
		i++;
	}
	i = 0;
	while (ordened[i] != NULL)
	{
		get_value(ordened[i]);
		i++;
	}
	free(ordened);
}

void	matrix_build(t_var *var)
{
	char	**sorted_vars;
	t_var	*current;
	size_t	i;

	i = 0;
	current = var;
	sorted_vars = ft_calloc(get_core()->env_vars_size + 1, sizeof(char *));
	if (!sorted_vars)
		ft_error("export: malloc failed", 1);
	while (current)
	{
		sorted_vars[i] = current->key;
		current = current->next;
		i++;
	}
	sorted_vars[i] = NULL;
	insert_sort(sorted_vars);
	free(sorted_vars);
}

void	export_variables(t_cmd *command)
{
	size_t	len;
	size_t	i;
	char	**split;

	i = 0;
	len = ft_matrix_len(command->args);
	if (ft_matrix_len(command->args) == 1)
		matrix_build(get_core()->env_vars);
	else
	{
		while (++i < len)
		{
			split = ft_split(command->args[i], '=');
			print_matrix(split);
			ft_free_matrix(split);
		}
	}
}
