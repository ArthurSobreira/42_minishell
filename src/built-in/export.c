/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:53 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/23 11:54:35 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_lstlen_var(t_var *var)
{
	size_t	len;
	t_var	*tmp;

	tmp = var;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	bubblesort(char **arr, size_t size)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j][0] > arr[j + 1][0])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	ft_print_matrix(arr);
}

void	matrix_build(t_var *var)
{
	char	**sorted_vars;
	size_t	size;
	t_var	*current;
	char	*msg;
	size_t	i;

	i = 0;
	current = var;
	msg = "declare -x ";
	size = ft_lstlen_var(var);
	sorted_vars = ft_calloc(size + 1, sizeof(char *));
	if (!sorted_vars)
		ft_error("export: malloc failed", 1);
	while (current)
	{
		sorted_vars[i] = current->key;
		current = current->next;
		i++;
	}
	bubblesort(sorted_vars, size);
	sorted_vars[i] = NULL;
	free(sorted_vars);
}

// while (tmp)
// {
// 	printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
// 	tmp = tmp->next;
// }
void	export_variables(t_cmd *command)
{
	if (ft_matrix_len(command->args) == 1)
		matrix_build(get_core()->env_vars);
}
