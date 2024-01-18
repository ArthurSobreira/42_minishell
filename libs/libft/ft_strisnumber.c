/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:19:47 by zeenyt            #+#    #+#             */
/*   Updated: 2023/12/09 15:57:26 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisnumber(char *str)
{
	int	index;

	index = 0;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index])
	{
		if (str[index] == ' ' || str[index] == '\t')
		{
			index++;
			continue ;
		}
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	return (1);
}
