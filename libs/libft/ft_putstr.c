/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:51:25 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 17:55:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(const char *s)
{
	size_t	counter;

	if (s == NULL)
		return (ft_putstr("(null)"));
	counter = ft_strlen(s);
	write(1, s, counter);
	return (counter);
}
