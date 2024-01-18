/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:56:14 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/11 18:22:13 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_putptr(size_t number, char *base)
{
	int	bytesread;
	int	base_len;

	bytesread = 0;
	base_len = ft_strlen(base);
	if (number == 0)
		return (ft_putstr("(nil)"));
	if (number >= (unsigned long)base_len)
		bytesread += ft_putptr((number / base_len), base);
	else
		bytesread += ft_putstr("0x");
	bytesread += ft_putchar(base[number % base_len]);
	return (bytesread);
}
