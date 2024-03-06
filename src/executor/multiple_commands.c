/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:04:26 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/06 10:58:54 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_pipelines(t_cmd *cmd_table)
{
	t_minishell	*core;
	size_t		index;

	core = get_core();
	index = 0;
	backup_fd_in_out(core->fd_backup);
	while (index <= core->pipe_count)
	{
		pipe(core->pipe_fd);
		cmd_table[index].pid = fork();
		signal(SIGINT, ctrl_c_child);
		signal(SIGQUIT, sigquit_f);
		if (cmd_table[index].pid < 0)
			return ;
		if (cmd_table[index].pid == 0)
			execute_multiple_child(&cmd_table[index]);
		else
			backup_pipe_fd();
		index++;
	}
	wait_all_childs(cmd_table);
	restore_fd_in_out();
}

void	execute_multiple_child(t_cmd *command)
{
	t_minishell	*core;

	core = get_core();
	if (is_empty_cmd(command))
	{
		close_all_fds();
		if (core->error_check.file_error[command->cmd_pos])
			core->exit_status = EXIT_FAILURE;
		clear_child(core);
	}
	else if (command->proc_type == INITIAL)
		handle_initial_proc(core, command);
	else if (command->proc_type == INTERMEDIATE)
		handle_intermediate_proc(core, command);
	else if (command->proc_type == FINAL)
		handle_final_proc(core, command);
}

void	handle_initial_proc(t_minishell *core, t_cmd *command)
{
	short	read_pipe;
	short	write_pipe;

	read_pipe = core->pipe_fd[0];
	write_pipe = core->pipe_fd[1];
	handle_child_fds(command);
	if (!command->redir_out)
	{
		close(read_pipe);
		dup2(write_pipe, STDOUT_FILENO);
		close(write_pipe);
	}
	if (command->is_builtin)
		execute_builtin(command, TRUE);
	else
	{
		if (execve(command->cmd, command->args, command->envp) < 0)
			handle_execve_error(command);
	}
}

void	handle_intermediate_proc(t_minishell *core, t_cmd *command)
{
	short	read_pipe;
	short	write_pipe;

	read_pipe = core->pipe_fd[0];
	write_pipe = core->pipe_fd[1];
	handle_child_fds(command);
	if (!command->redir_out)
	{
		close(read_pipe);
		dup2(write_pipe, STDOUT_FILENO);
		close(write_pipe);
	}
	if (!command->redir_in)
	{
		close(write_pipe);
		close(read_pipe);
	}
	if (command->is_builtin)
		execute_builtin(command, TRUE);
	else
	{
		if (execve(command->cmd, command->args, command->envp) < 0)
			handle_execve_error(command);
	}
}

void	handle_final_proc(t_minishell *core, t_cmd *command)
{
	short	read_pipe;
	short	write_pipe;

	read_pipe = core->pipe_fd[0];
	write_pipe = core->pipe_fd[1];
	handle_child_fds(command);
	if (!command->redir_in)
	{
		close(write_pipe);
		close(read_pipe);
	}
	if (command->is_builtin)
		execute_builtin(command, TRUE);
	else
	{
		if (execve(command->cmd, command->args, command->envp) < 0)
			handle_execve_error(command);
	}
}
