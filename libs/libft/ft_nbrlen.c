/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:20:02 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 18:05:00 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int long nbr)
{
	size_t	len;

	len = 1;
	if (!nbr)
		return (len);
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
