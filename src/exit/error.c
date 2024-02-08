/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:34:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/08 18:31:13 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *str, int status)
{
	t_minishell	*core;
	char		*msg;

	core = get_core();
	if (core->error_msg)
	{
		msg = ft_strjoin("minishell: ", str);
		ft_putstr_fd(msg, STDERR_FILENO);
		free(msg);
		core->error_msg = FALSE;
	}
	core->exit_status = status;
}
