/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:31:31 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 15:38:44 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*array;
	size_t	total_size;

	if (num_elements == 0 || element_size == 0)
		return (malloc(0));
	else
	{
		total_size = num_elements * element_size;
		array = malloc(total_size);
		if (array == NULL)
			return (NULL);
		ft_bzero(array, total_size);
	}
	return (array);
}
