/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:36:29 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 15:38:36 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *array, int value, size_t num)
{
	char	*temp;
	size_t	counter;

	temp = (char *)array;
	counter = 0;
	while (counter < num)
	{
		temp[counter] = value;
		counter++;
	}
	return (array);
}
