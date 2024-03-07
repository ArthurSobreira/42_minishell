/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:50:48 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/07 12:58:19 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	verify_flag(t_cmd *command, int *index)
{
	t_bool	n_flag;
	size_t	arg_index;
	char	**args;

	n_flag = FALSE;
	args = command->args;
	while (args[*index] && args[*index][0] == '-')
	{
		arg_index = 1;
		while (args[*index][arg_index] == 'n')
		{
			arg_index++;
			n_flag = TRUE;
		}
		if (args[*index][arg_index] != '\0')
			return (n_flag);
		(*index)++;
	}
	return (n_flag);
}

void	echo(t_cmd *command)
{
	t_bool	n_flag;
	int		index;
	int		fd_out;

	index = 1;
	n_flag = TRUE;
	fd_out = STDOUT_FILENO;
	if (command->redir_out)
		fd_out = command->redir_out->fd_out;
	if (verify_flag(command, &index))
		n_flag = FALSE;
	while (command->args[index])
	{
		ft_putstr_fd(command->args[index], fd_out);
		if (command->args[index + 1])
			ft_putchar_fd(' ', fd_out);
		index++;
	}
	if (n_flag)
		ft_putchar_fd('\n', fd_out);
	get_core()->exit_status = EXIT_SUCCESS;
}
