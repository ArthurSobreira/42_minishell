/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:21:52 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/03 18:29:25 by phenriq2         ###   ########.fr       */
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

void	insert_sort(char **arr, int fd)
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
		print_ordened_values(ordened[i], fd);
		i++;
	}
	free(ordened);
}
