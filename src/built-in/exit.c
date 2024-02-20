/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:35:52 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/20 11:58:43 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(void)
{
	t_minishell	*core;

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
