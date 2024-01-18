/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:21:31 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 15:38:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_string;
	unsigned int	index;

	index = 0;
	if (!(*s || *f))
		return (0);
	new_string = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!new_string)
		return (0);
	while (s[index])
	{
		new_string[index] = f(index, s[index]);
		index++;
	}
	new_string[index] = '\0';
	return (new_string);
}
