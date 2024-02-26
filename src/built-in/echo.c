/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:50:48 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/26 17:32:57 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(t_cmd *command)
{
	int	i;
	int	n_flag;
	int	fd_out;

	get_core()->exit_status = EXIT_SUCCESS;
	i = 1;
	n_flag = 0;
	fd_out = STDOUT_FILENO;
	if (command->redir_out)
		fd_out = command->redir_out->fd_out;
	if (ft_matrix_len(command->args) > 1 && ft_strcmp(command->args[1],
			"-n") == 0)
	{
		n_flag = 1;
		i++;
	}
	while (command->args[i])
	{
		ft_putstr_fd(command->args[i], fd_out);
		if (command->args[i + 1])
			ft_putchar_fd(' ', fd_out);
		i++;
	}
	if (!n_flag)
		ft_putchar_fd('\n', fd_out);
}
