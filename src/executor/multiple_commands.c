/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:04:26 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/01 15:18:18 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	validate_empty_cmd(t_cmd *cmd, size_t *index)
{
	t_minishell	*core;

	core = get_core();
	if (cmd->cmd == NULL || cmd->cmd[0] == '\0' || \
		core->error_check.cmd_error[*index])
	{
		(*index)++;
		return (TRUE);
	}
	return (FALSE);
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

// void	restore_fd_in_out(void)
// {
// 	dup2(STDIN_FILENO, 0);
// 	dup2(STDOUT_FILENO, 1);
// }

void	execute_pipelines(t_cmd *cmd_table)
{
	t_minishell	*core;
	size_t		index;

	core = get_core();
	index = 0;
	while (index <= core->pipe_count)
	{
		if (validate_empty_cmd(&cmd_table[index], &index))
			continue ;
		pipe(core->pipe_fd);
		cmd_table[index].pid = fork();
		if (cmd_table[index].pid < 0)
			return ;
		if (cmd_table[index].pid == 0)
			execute_multiple_child(&cmd_table[index]);
		else
		{
			dup2(core->pipe_fd[0], STDIN_FILENO);
			close(core->pipe_fd[0]);
			close(core->pipe_fd[1]);
		}
		index++;
	}
	wait_all_childs(cmd_table);
	// restore_fd_in_out();
}

void	execute_multiple_child(t_cmd *command)
{
	t_minishell	*core;

	core = get_core();
	if (command->proc_type == INITIAL)
		handle_initial_proc(core, command);
	// else if (command->proc_type == INTERMEDIATE)
	// 	handle_intermediate_proc(command);
	else if (command->proc_type == FINAL)
		handle_final_proc(core, command);
}

void	handle_initial_proc(t_minishell *core, t_cmd *command)
{
	short	read_pipe;
	short	write_pipe;

	read_pipe = core->pipe_fd[0];
	write_pipe = core->pipe_fd[1];
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
	else if (!command->redir_out)
	{
		close(read_pipe);
		dup2(write_pipe, STDOUT_FILENO);
		close(write_pipe);
	}
	if (execve(command->cmd, command->args, command->envp) < 0)
		handle_execve_error(command);
}

void	handle_final_proc(t_minishell *core, t_cmd *command)
{
	short	read_pipe;
	short	write_pipe;

	read_pipe = core->pipe_fd[0];
	write_pipe = core->pipe_fd[1];
	if (command->redir_out)
	{
		dup2(command->redir_out->fd_out, STDOUT_FILENO);
		close(command->redir_out->fd_out);
	}
	if (command->redir_in)
	{
		dup2(command->redir_in->fd_in, STDIN_FILENO);
		close(command->redir_in->fd_in);
	}
	else if (!command->redir_in)
	{
		close(write_pipe);
		close(read_pipe);
	}
	if (execve(command->cmd, command->args, command->envp) < 0)
		handle_execve_error(command);
}
