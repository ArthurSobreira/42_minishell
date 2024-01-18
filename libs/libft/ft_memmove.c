/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 08:19:08 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 15:38:36 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_verify(char *dest, const char *end, size_t num)
{
	size_t	counter;

	if (((dest == end) && (dest == NULL)))
		return ;
	if (dest > end && dest < end + num)
	{
		counter = num;
		while (counter > 0)
		{
			dest[counter - 1] = end[counter - 1];
			counter--;
		}
	}
	else
	{
		counter = 0;
		while (counter < num)
		{
			dest[counter] = end[counter];
			counter++;
		}
	}
}

void	*ft_memmove(void *array, const void *src, size_t num)
{
	char		*dest;
	const char	*end;

	dest = (char *)array;
	end = (const char *)src;
	ft_verify(dest, end, num);
	return (array);
}
