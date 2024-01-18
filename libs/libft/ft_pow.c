/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:23:55 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/16 11:24:49 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int base, int exp)
{
	int	result;

	result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}
	return (result);
}
