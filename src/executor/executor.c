/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:45:51 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/26 11:22:43 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_executor(void)
{
	t_minishell	*core;

	core = get_core();
	create_cmd_table();
	if (!core->error_check.file_error[0] && !core->cmd_table[0].is_builtin)
	{
		core->cmd_table[0].pid = fork();
		if (core->cmd_table[0].pid == 0)
		{
			if (execve(core->cmd_table[0].cmd,
					core->cmd_table[0].args, NULL) == -1)
				perror("minishell");
		}
		waitpid(core->cmd_table[0].pid, NULL, 0);
	}
}
