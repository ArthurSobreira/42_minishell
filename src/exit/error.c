/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:34:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/01 14:17:10 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *str, int status)
{
	t_minishell	*core;

	core = get_core();
	ft_putstr_fd(str, STDERR_FILENO);
	if (core->input != NULL)
		free(core->input);
	if (core->splited_input != NULL)
		ft_clear_splited_input();
	if (core->env_vars != NULL)
		ft_clear_env_vars();
	exit(status);
}
