/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 08:24:36 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 15:38:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	counter;
	size_t	total;
	size_t	size_dst;
	size_t	size_src;

	counter = 0;
	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	total = size_src + size_dst;
	if (size <= size_dst)
		return (size + size_src);
	while (src[counter] && (size_dst + counter + 1) < size)
	{
		dst[size_dst + counter] = src[counter];
		counter++;
	}
	dst[size_dst + counter] = '\0';
	return (total);
}
