/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:56:43 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/05 16:26:29 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;

	if (!s1 || !s2)
		return (1);
	index = 0;
	while ((s1[index]) && (s1[index] == s2[index]))
	{
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
