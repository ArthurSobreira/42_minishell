/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:09:59 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/03 17:53:16 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putnbr_base_fd(long int number, char *base, int fd)
{
	int	base_length;

	base_length = ft_strlen(base);
	if (number < 0)
	{
		ft_putchar_fd('-', fd);
		number *= -1;
	}
	if (number >= base_length)
		ft_putnbr_base_fd((number / base_length), base, fd);
	ft_putchar_fd(base[number % base_length], fd);
}
