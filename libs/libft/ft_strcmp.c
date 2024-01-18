/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:33:53 by zeenyt            #+#    #+#             */
/*   Updated: 2023/12/08 14:17:05 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	if (s1 == NULL || s2 == NULL)
		return (0);
	index = 0;
	while (s1[index] && s2[index] && s1[index] == s2[index])
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
