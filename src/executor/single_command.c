/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:59:17 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/29 17:29:23 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_single_command(t_cmd *command)
{
	t_minishell	*core;
	int			status;

	core = get_core();
	if (command->cmd == NULL || command->cmd[0] == '\0' || \
		core->error_check.cmd_error[command->cmd_pos])
		return ;
	status = 0;
	command->pid = fork();
	if (command->pid < 0)
		return ;
	if (command->pid == 0)
		exec_single_child(command);
	else
	{
		waitpid(command->pid, &status, 0);
		if (WIFEXITED(status))
			core->exit_status = WEXITSTATUS(status);
	}
}

void	exec_single_child(t_cmd *command)
{
	t_minishell	*core;

	core = get_core();
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
	if (execve(command->cmd, command->args, core->envp) < 0)
		handle_execve_error(command);
}

void	handle_execve_error(t_cmd *command)
{
	char	*cmd_error;
	int		exit_status;

	cmd_error = NULL;
	exit_status = CMD_NOT_FOUND;
	if (ft_strchr(command->cmd, '/') || ft_strchr(command->cmd, '.'))
	{
		if (!check_file_exists(command->cmd))
			cmd_error = ft_strjoin(command->cmd, ": No such file or directory");
		else if (check_file_executable(command->cmd))
		{
			cmd_error = ft_strjoin(command->cmd, ": Is a directory");
			exit_status = IS_A_DIRECTORY;
		}
		else if (!check_file_executable(command->cmd))
		{
			cmd_error = ft_strjoin(command->cmd, ": Permission denied");
			exit_status = IS_A_DIRECTORY;
		}
	}
	else
		cmd_error = ft_strjoin(command->cmd, ": command not found");
	ft_error(cmd_error, exit_status);
	free(cmd_error);
	exit_shell(command);
}
