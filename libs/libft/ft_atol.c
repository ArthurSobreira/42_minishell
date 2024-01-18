/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:49:39 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/09 19:02:56 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	size_t	i;
	long	result;
	int		is_negative;

	i = 0;
	result = 0;
	is_negative = 1;
	while (((nptr[i] >= 9) && (nptr[i] <= 13)) || ((nptr[i]) == 32))
	{
		i++;
	}
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if ((nptr[i] == '-'))
			is_negative *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return (result * is_negative);
}
