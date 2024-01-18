/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 08:27:02 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 15:38:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	counter;
	size_t	index;

	counter = 0;
	if (!*little)
		return ((char *)big);
	while (big[counter] && counter < len)
	{
		index = 0;
		while ((big[counter + index] && little[index]) && (big[counter \
		+ index] == little[index]))
			index++;
		if (!little[index] && (counter + index <= len))
			return ((char *)&big[counter]);
		counter++;
	}
	return (NULL);
}
