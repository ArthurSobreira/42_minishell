/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:22:45 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/26 15:43:05 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_wipe_list(t_gnl **list_of_char, int counter)
{
	t_gnl	*current;
	t_gnl	*temp;

	current = *list_of_char;
	if (counter == -1)
	{
		while (current != NULL)
		{
			temp = current;
			current = current->next;
			free(temp);
		}
		*list_of_char = current;
	}
	else
	{
		while (counter > 0 && current != NULL)
		{
			temp = current;
			current = current->next;
			free(temp);
			counter--;
		}
		*list_of_char = current;
	}
}

int	ft_read_error(t_gnl **main_list, char *current)
{
	ft_wipe_list(main_list, -1);
	*main_list = NULL;
	free(current);
	return (1);
}

int	ft_sizelst(t_gnl **list_of_char, char c)
{
	t_gnl	*size;
	int		counter;

	size = *list_of_char;
	counter = 1;
	while (size != NULL && size->data != c)
	{
		counter++;
		size = size->next;
	}
	return (counter);
}

void	ft_start_gnl(t_gnl **caracter, char c)
{
	t_gnl	*new_list;

	new_list = (t_gnl *)malloc(sizeof(t_gnl));
	if (new_list != NULL)
	{
		new_list->data = c;
		new_list->next = NULL;
		*caracter = new_list;
	}
}
