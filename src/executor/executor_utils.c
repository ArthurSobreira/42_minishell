/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:09:37 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/05 15:21:44 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_execve_error(t_cmd *command)
{
	char	*cmd_error;
	int		exit_status;

	cmd_error = NULL;
	exit_status = CMD_NOT_FOUND;
	if (ft_strchr(command->cmd, '/') || ft_strstr(command->cmd, "./"))
	{
		if (!check_file_exists(command->cmd))
			cmd_error = ft_strjoin(command->cmd, NO_SUCH_FILE);
		else if (check_file_executable(command->cmd))
		{
			cmd_error = ft_strjoin(command->cmd, NOT_A_FILE);
			exit_status = IS_A_DIRECTORY;
		}
		else if (!check_file_executable(command->cmd))
		{
			cmd_error = ft_strjoin(command->cmd, NO_PERMISSION);
			exit_status = IS_A_DIRECTORY;
		}
	}
	else
		cmd_error = ft_strjoin(command->cmd, NO_SUCH_CMD);
	ft_error(cmd_error, exit_status);
	free(cmd_error);
	exit_shell(command);
}

void	wait_all_childs(t_cmd *cmd_table)
{
	t_minishell	*core;
	size_t		index;
	int			status;

	core = get_core();
	index = 0;
	while (index <= core->pipe_count)
	{
		status = 0;
		waitpid(cmd_table[index].pid, &status, 0);
		if (WIFEXITED(status))
			core->exit_status = WEXITSTATUS(status);
		index++;
	}
}

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
