/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:46:42 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/06 10:51:00 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_child_fds(t_cmd *command)
{
	if (command->is_builtin)
		return ;
	if (command->redir_in)
	{
		dup2(command->redir_in->fd_in, STDIN_FILENO);
		close(command->redir_in->fd_in);
	}
	if (command->redir_out)
	{
		dup2(command->redir_out->fd_out, STDOUT_FILENO);
		close(command->redir_out->fd_out);
	}
}

void	backup_pipe_fd(void)
{
	t_minishell	*core;

	core = get_core();
	dup2(core->pipe_fd[0], STDIN_FILENO);
	close(core->pipe_fd[0]);
	close(core->pipe_fd[1]);
}

void	backup_fd_in_out(int fd_backup[2])
{
	fd_backup[0] = dup(STDIN_FILENO);
	fd_backup[1] = dup(STDOUT_FILENO);
}

void	restore_fd_in_out(void)
{
	t_minishell	*core;

	core = get_core();
	dup2(core->fd_backup[0], STDIN_FILENO);
	dup2(core->fd_backup[1], STDOUT_FILENO);
	close(core->fd_backup[0]);
	close(core->fd_backup[1]);
}

void	close_all_fds(void)
{
	size_t	index;

	index = 4;
	while (index <= 1024)
	{
		close(index);
		index++;
	}
}
