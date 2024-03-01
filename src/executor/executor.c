/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:45:51 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/01 15:06:59 by arsobrei         ###   ########.fr       */
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
	ft_putstr_fd("teste in\n", STDIN_FILENO);
	ft_putstr_fd("teste out\n", STDOUT_FILENO);
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
