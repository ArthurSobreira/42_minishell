/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:35:52 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/26 15:14:38 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(t_cmd *command)
{
	t_minishell	*core;

	if (command && ft_matrix_len(command->args) > 1)
	{
		ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
		return ;
	}
	core = get_core();
	if (core->token_list != NULL)
		ft_clear_token();
	if (core->env_vars != NULL)
		ft_clear_env_vars();
	if (core->cmd_table != NULL)
		ft_clear_cmd_table();
	clear_garbage();
	ft_error("bye bye\n", EXIT_SUCCESS);
	exit(core->exit_status);
}
