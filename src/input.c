/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:15:36 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/22 10:22:50 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_analysis(t_minishell *core)
{
	char	*command;

	command = core->input[0].value;
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
