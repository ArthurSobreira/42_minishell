/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:35:52 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/07 19:52:28 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(void)
{
	t_minishell	*core;

	core = get_core();
	if (core->input != NULL)
		free(core->input);
	if (core->splited_input != NULL)
		ft_clear_splited_input();
	if (core->env_vars != NULL)
		ft_clear_env_vars();
	ft_error("bye bye\n", EXIT_SUCCESS);
	exit(core->exit_status);
}
