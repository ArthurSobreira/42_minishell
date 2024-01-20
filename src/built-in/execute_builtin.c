/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:05:53 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/20 15:11:29 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_builtin(t_minishell *core)
{
	char	*command;

	command = ((t_cmd *)(core->command_list->content))->input;
	printf("command: %s\n", command);
	if (!ft_strcmp(command, core->built_in[0]))
		echo(core);
	else if (!ft_strcmp(command, core->built_in[1]))
		change_directory(core);
	else if (!ft_strcmp(command, core->built_in[2]))
		print_working_directory(core);
	else if (!ft_strcmp(command, core->built_in[3]))
		export_variables(core);
	else if (!ft_strcmp(command, core->built_in[4]))
		unset(core);
	else if (!ft_strcmp(command, core->built_in[5]))
		environment(core);
	else if (!ft_strcmp(command, core->built_in[6]))
		exit(0);
	else
		ft_putstr_fd("is not a built-in command\n", 0);
}
