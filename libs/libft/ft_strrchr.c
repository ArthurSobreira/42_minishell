/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 08:27:18 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 15:38:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last);
}
