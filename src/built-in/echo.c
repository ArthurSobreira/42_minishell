/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:50:48 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/22 12:16:10 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(t_cmd *command)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if (ft_matrix_len(command->args) > 1 && ft_strcmp(command->args[1],
			"-n") == 0)
	{
		n_flag = 1;
		i++;
	}
	while (command->args[i])
	{
		ft_putstr_fd(command->args[i], STDOUT_FILENO);
		if (command->args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (!n_flag)
		ft_putchar_fd('\n', STDOUT_FILENO);
}
