/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:45:11 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/03 17:53:29 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putptr_fd(unsigned long number, char *base, int fd)
{
	int	base_length;

	base_length = ft_strlen(base);
	if (number == 0)
		ft_putstr_fd("(nil)", fd);
	if (number >= (unsigned long)base_length)
		ft_putptr_fd((number / base_length), base, fd);
	else
		ft_putstr_print("0x");
	ft_putchar_fd(base[number % base_length], fd);
}
