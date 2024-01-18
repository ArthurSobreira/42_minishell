/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:13:15 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/08 14:14:05 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr(long int n)
{
	size_t	len_read;
	char	*base;

	base = "0123456789";
	len_read = 0;
	if (n < 0)
	{
		n = -n;
		len_read++;
		write(1, "-", 1);
	}
	while (n >= 10)
	{
		len_read++;
		write(1, &base[n % 10], 1);
		n = n / 10;
	}
	write(1, &base[n], 1);
	len_read++;
	return (len_read);
}
