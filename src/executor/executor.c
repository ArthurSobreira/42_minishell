/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:45:51 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/04 12:35:14 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_executor(void)
{
	t_minishell	*core;

	core = get_core();
	create_cmd_table();
	if (!core->pipe_count)
	{
		if (core->cmd_table[0].is_builtin)
			execute_builtin(&core->cmd_table[0]);
		else
			execute_single_command(&core->cmd_table[0]);
	}
	else
		execute_pipelines(core->cmd_table);
}

void	execute_builtin(t_cmd *command)
{
	if (!ft_strcmp(command->cmd, "cd"))
		change_directory(command);
	else if (!ft_strcmp(command->cmd, "echo"))
		echo(command);
	else if (!ft_strcmp(command->cmd, "env"))
		print_env_variables(command);
	else if (!ft_strcmp(command->cmd, "exit"))
		exit_shell(command);
	else if (!ft_strcmp(command->cmd, "export"))
		export_variables(command);
	else if (!ft_strcmp(command->cmd, "pwd"))
		print_working_directory(command);
	else if (!ft_strcmp(command->cmd, "unset"))
		unset(command);
}

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
	signal(SIGINT, ctrl_c_child);
	signal(SIGQUIT, sigquit_f);
	if (command->pid < 0)
		return ;
	if (command->pid == 0)
	{
		handle_fds(command);
		if (execve(command->cmd, command->args, command->envp) < 0)
			handle_execve_error(command);
	}
	else
	{
		waitpid(command->pid, &status, 0);
		if (WIFEXITED(status))
			core->exit_status = WEXITSTATUS(status);
	}
}
