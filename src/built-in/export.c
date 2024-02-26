/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:53 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/26 19:39:30 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		print_ordened_values(ordened[i]);
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

t_bool	set_value_on_existing_key(char *key, char *value)
{
	t_var	*tmp;

	tmp = get_core()->env_vars;
	if (!key)
		return (FALSE);
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			if (!value)
				tmp->value = NULL;
			else
				tmp->value = ft_strdup(value);
			return (TRUE);
		}
		tmp = tmp->next;
	}
	return (FALSE);
}

void	export_variables(t_cmd *command)
{
	size_t	i;
	char	*key;
	char	*value;

	i = 0;
	get_core()->exit_status = EXIT_SUCCESS;
	if (ft_matrix_len(command->args) == 1)
		matrix_build(get_core()->env_vars);
	else
	{
		while (++i < ft_matrix_len(command->args))
		{
			if (!is_valide_argument(command->args[i]))
				return ;
			key = return_key(command->args[i]);
			value = return_value(command->args[i]);
			if (!set_value_on_existing_key(key, value))
			{
				add_end_var(&get_core()->env_vars, create_var(key, value));
				get_core()->env_vars_size++;
			}
			free(key);
			free(value);
		}
	}
}
