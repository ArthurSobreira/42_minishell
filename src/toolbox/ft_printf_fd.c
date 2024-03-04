/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:27:30 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/03 17:57:59 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_check_format_fd(va_list args, char current_format, int fd);

void	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	size_t	index;

	if (format == NULL)
		return ;
	va_start(args, format);
	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			ft_check_format_fd(args, format[index], fd);
		}
		else
			ft_putchar_fd(format[index], fd);
		index++;
	}
	va_end(args);
}

static void	ft_check_format_fd(va_list args, char current_format, int fd)
{
	if (current_format == 'c')
		ft_putchar_fd((char)va_arg(args, int), fd);
	else if (current_format == 's')
		ft_putstr_fd(va_arg(args, char *), fd);
	else if (current_format == 'p')
		ft_putptr_fd(va_arg(args, unsigned long), HEXA_LOW_BASE, fd);
	else if (current_format == 'd' || current_format == 'i')
		ft_putnbr_base_fd(va_arg(args, int), DECIMAL_BASE, fd);
	else if (current_format == 'u')
		ft_putnbr_base_fd(va_arg(args, unsigned int), DECIMAL_BASE, fd);
	else if (current_format == 'x')
		ft_putnbr_base_fd(va_arg(args, unsigned int), HEXA_LOW_BASE, fd);
	else if (current_format == 'X')
		ft_putnbr_base_fd(va_arg(args, unsigned int), HEXA_UP_BASE, fd);
	else if (current_format == '%')
		ft_putchar_fd('%', fd);
}
