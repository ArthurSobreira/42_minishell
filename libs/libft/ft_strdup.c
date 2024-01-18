/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:00:28 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/26 15:41:43 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		counter;
	char	*copy;

	counter = 0;
	while (src[counter] != '\0')
		counter++;
	copy = malloc(counter + 1);
	if (copy == NULL)
		return (NULL);
	counter = 0;
	while (src[counter] != '\0')
	{
		copy[counter] = src[counter];
		counter++;
	}
	copy[counter] = '\0';
	return (copy);
}
