/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:35:52 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/12 18:09:32 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(void)
{
	t_minishell	*core;

	core = get_core();
	clear_garbage();
	if (core->env_vars != NULL)
		ft_clear_env_vars();
	ft_error("bye bye\n", EXIT_SUCCESS);
	exit(core->exit_status);
}
