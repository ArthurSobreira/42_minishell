/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:34:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/13 16:46:39 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *str, int status)
{
	t_minishell	*core;
	char		*msg;

	core = get_core();
	msg = ft_strjoin("minishell: ", str);
	ft_putendl_fd(msg, STDERR_FILENO);
	free(msg);
	core->exit_status = status;
}

void	ft_file_error(char *file_name, char *str, int status)
{
	t_minishell	*core;
	char		*msg;
	char		*tmp_file_name;

	core = get_core();
	core->error_check.file_error = TRUE;
	tmp_file_name = ft_strjoin(file_name, ": ");
	msg = ft_strjoin_three("minishell: ", tmp_file_name, str);
	ft_putstr_fd(msg, STDERR_FILENO);
	free(msg);
	free(tmp_file_name);
	core->exit_status = status;
}
