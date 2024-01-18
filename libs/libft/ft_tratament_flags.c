/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tratament_flags.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:38:23 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/13 11:02:23 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	tratament_flags_advanced(char chr, int *index)
{
	int	flag;

	flag = -42;
	if (chr == '#')
	{
		flag = 1;
	}
	else if (chr == '+')
	{
		flag = 2;
	}
	else
		flag = 4;
	(*index)++;
	return (flag);
}

int	tratament_flags(char chr, va_list args, int flag)
{
	int	counter;

	counter = 0;
	if (chr == 'c')
		counter = flag_c(args);
	else if (chr == '%')
		counter = flag_percent();
	else if (chr == 'p')
		counter = flag_p(args);
	else if (chr == 's')
		counter = flag_s(args);
	else if (chr == 'd' || chr == 'i')
		counter = flag_di(args, flag);
	else if (chr == 'u')
		counter = flag_u(args, flag);
	else if (chr == 'x')
		counter = flag_x(args, flag);
	else if (chr == 'X')
		counter = flag_x2(args, flag);
	else if (chr == ' ')
		counter = flag_space();
	return (counter);
}
