/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:01:39 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 15:38:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long int nbr, char *base)
{
	t_variables	itoa;

	itoa.len_base = ft_strlen(base);
	itoa.len = ft_nbrlen(nbr);
	itoa.str = malloc((itoa.len + 1) * sizeof(char));
	if (itoa.str == NULL)
		return (NULL);
	itoa.str[itoa.len] = '\0';
	if (nbr == 0)
	{
		itoa.str[0] = base[0];
		return (itoa.str);
	}
	if (nbr < 0)
	{
		itoa.str[0] = '-';
		nbr = -nbr;
	}
	while (itoa.len > 0 && itoa.str[itoa.len - 1] != '-')
	{
		itoa.str[--itoa.len] = base[nbr % itoa.len_base];
		nbr /= itoa.len_base;
	}
	return (itoa.str);
}
