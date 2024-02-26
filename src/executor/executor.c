/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:45:51 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/26 15:17:07 by phenriq2         ###   ########.fr       */
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
		// else
		// 	execute_single_command(&core->cmd_table[0]);
		return ;
	}
	core->cmd_table[0].pid = fork();
	if (!core->error_check.file_error[0] && !core->cmd_table[0].is_builtin)
	{
		core->cmd_table[0].pid = fork();
		if (core->cmd_table[0].pid == 0)
		{
			if (core->cmd_table[0].cmd != NULL)
			if (execve(core->cmd_table[0].cmd, \
				core->cmd_table[0].args, core->cmd_table[0].envp) == -1)
			{
				perror("minishell");
			}
		}
	}
	waitpid(core->cmd_table[0].pid, NULL, 0);
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
