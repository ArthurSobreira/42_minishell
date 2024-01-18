/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 08:17:45 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 15:38:36 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*array_1;
	const unsigned char	*array_2;
	size_t				counter;

	counter = 0;
	array_1 = s1;
	array_2 = s2;
	while (counter < n)
	{
		if (array_1[counter] > array_2[counter])
			return (1);
		if (array_1[counter] < array_2[counter])
			return (-1);
		counter++;
	}
	return (0);
}
