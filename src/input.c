/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:15:36 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/18 10:32:13 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	input_analysis(t_minishell *core)
{
	char	*command;

	command = core->input[0].value;
	if (!ft_strcmp(command, core->built_in[0]))
		ft_putstr_fd("ok\n", 0);
	else if (!ft_strcmp(command, core->built_in[1]))
		ft_putstr_fd("ok\n", 0);
	else if (!ft_strcmp(command, core->built_in[2]))
		ft_putstr_fd("ok\n", 0);
	else if (!ft_strcmp(command, core->built_in[3]))
		ft_putstr_fd("ok\n", 0);
	else if (!ft_strcmp(command, core->built_in[4]))
		ft_putstr_fd("ok\n", 0);
	else if (!ft_strcmp(command, core->built_in[5]))
		ft_putstr_fd("ok\n", 0);
	else if (!ft_strcmp(command, core->built_in[6]))
		exit(0);
	else
		ft_putstr_fd("is not a built-in command\n", 0);
}
