/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:45:51 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/23 18:08:07 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_default_fds(void)
{
	t_minishell	*core;

	core = get_core();
	core->default_fds[0] = dup(STDIN_FILENO);
	core->default_fds[1] = dup(STDOUT_FILENO);
}

void	restore_default_fds(void)
{
	t_minishell	*core;

	core = get_core();
	dup2(core->default_fds[0], STDIN_FILENO);
	dup2(core->default_fds[1], STDOUT_FILENO);
	close(core->default_fds[0]);
	close(core->default_fds[1]);
}

void	redirect_fds(t_cmd *command)
{
	if (command->redir_in != NULL)
	{
		if (command->redir_in->fd_in >= 0)
			dup2(command->redir_in->fd_in, STDIN_FILENO);
	}
	if (command->redir_out != NULL)
	{
		if (command->redir_out->fd_out >= 0)
			dup2(command->redir_out->fd_out, STDOUT_FILENO);
	}
}

void	execute_builtin(t_cmd *command)
{
	if (command->redir_in || command->redir_out)
		save_default_fds();
	redirect_fds(command);
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
	if (!get_core()->pipe_count)
		restore_default_fds();
}

void	command_executor(void)
{
	t_minishell	*core;

	core = get_core();
	create_cmd_table();
	if (!core->pipe_count && core->cmd_table[0].is_builtin)
	{
		execute_builtin(&core->cmd_table[0]);
		return ;
	}
	
// 	core->cmd_table[0].pid = fork();
// 	if (!core->error_check.file_error[0] && !core->cmd_table[0].is_builtin)
// 	{
// 		if (core->cmd_table[0].pid == 0)
// 		{
// 			if (execve(core->cmd_table[0].cmd, \
// 				core->cmd_table[0].args, core->cmd_table[0].envp) == -1)
// 				perror("minishell");
// 		}
// 	}
// 	waitpid(core->cmd_table[0].pid, NULL, 0);
}
