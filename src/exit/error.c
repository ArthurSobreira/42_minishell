/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:34:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/01 22:33:43 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *str, int status)
{
	t_minishell	*core;
	char		*msg;

	core = get_core();
	msg = ft_strjoin("minishell: ", str);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (core->input != NULL)
		free(core->input);
	if (core->splited_input != NULL)
		ft_clear_splited_input();
	if (core->env_vars != NULL)
		ft_clear_env_vars();
	free(msg);
	exit(status);
}
