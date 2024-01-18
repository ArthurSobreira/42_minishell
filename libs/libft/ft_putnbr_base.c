/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:32:12 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/11 18:21:37 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_base(long int number, char *base)
{
	size_t	bytesread;
	int		base_len;

	bytesread = 0;
	base_len = ft_strlen(base);
	if (!base || base_len < 2)
		return (0);
	if (number < 0)
	{
		bytesread += write(1, "-", 1);
		number *= -1;
	}
	if (number >= base_len)
		bytesread += ft_putnbr_base((number / base_len), base);
	bytesread += write(1, &base[number % base_len], 1);
	return (bytesread);
}
