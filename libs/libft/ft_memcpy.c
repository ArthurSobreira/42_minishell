/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 08:18:22 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 15:38:36 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *array, const void *src, size_t num)
{
	char		*dest;
	const char	*end;
	size_t		counter;

	dest = (char *)array;
	end = (const char *)src;
	counter = 0;
	if (!(dest || end))
		return (0);
	while (counter < num)
	{
		dest[counter] = end[counter];
		counter++;
	}
	return (array);
}
