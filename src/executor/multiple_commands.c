/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:04:26 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/04 12:39:54 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	execute_pipelines(t_cmd *cmd_table)
{
	t_minishell	*core;
	size_t		index;

	core = get_core();
	index = 0;
	backup_fd_in_out(core->fd_backup);
	while (index <= core->pipe_count)
	{
		if (validate_empty_cmd(&cmd_table[index], &index))
			continue ;
		pipe(core->pipe_fd);
		cmd_table[index].pid = fork();
		signal(SIGINT, ctrl_c_child);
		signal(SIGQUIT, sigquit_f);
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
	restore_fd_in_out();
}

void	execute_multiple_child(t_cmd *command)
{
	t_minishell	*core;

	core = get_core();
	if (command->proc_type == INITIAL)
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
	handle_fds(command);
	if (!command->redir_out)
	{
		close(read_pipe);
		dup2(write_pipe, STDOUT_FILENO);
		close(write_pipe);
	}
	if (command->is_builtin)
	{
		execute_builtin(command);
		exit_shell(command);
	}
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
	handle_fds(command);
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
	{
		execute_builtin(command);
		exit_shell(command);
	}
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
	handle_fds(command);
	if (!command->redir_in)
	{
		close(write_pipe);
		close(read_pipe);
	}
	if (command->is_builtin)
	{
		execute_builtin(command);
		exit_shell(command);
	}
	else
	{
		if (execve(command->cmd, command->args, command->envp) < 0)
			handle_execve_error(command);
	}
}
