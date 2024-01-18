/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:15:00 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/26 15:41:52 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	counter;
	size_t	index;

	counter = 0;
	index = 0;
	new_string = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_string)
		return (0);
	while (s1[counter])
		new_string[index++] = s1[counter++];
	counter = 0;
	while (s2[counter])
		new_string[index++] = s2[counter++];
	new_string[index] = '\0';
	return (new_string);
}
