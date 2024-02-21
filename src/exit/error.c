/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:34:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/21 12:11:54 by arsobrei         ###   ########.fr       */
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

void	ft_file_error(char *file_name, char *str, int status, size_t index)
{
	t_minishell	*core;
	char		*msg;
	char		*tmp_file_name;

	core = get_core();
	if (core->error_check.file_error[index] == TRUE)
		return ;
	core->error_check.file_error[index] = TRUE;
	tmp_file_name = ft_strjoin(file_name, ": ");
	msg = ft_strjoin_three("minishell: ", tmp_file_name, str);
	ft_putstr_fd(msg, STDERR_FILENO);
	free(msg);
	free(tmp_file_name);
	unlink(HERE_DOC_FILE);
	core->exit_status = status;
}
