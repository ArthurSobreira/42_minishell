/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:46 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/26 16:55:20 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_var(char *key, char *value, int fd_out)
{
	ft_putstr_fd(key, fd_out);
	ft_putstr_fd("=", fd_out);
	if (value)
		ft_putendl_fd(value, fd_out);
	else
		ft_putchar_fd('\n', fd_out);
}

void	print_env_variables(t_cmd *command)
{
	t_minishell	*core;
	t_var		*current_var;
	int			fd_out;

	fd_out = STDOUT_FILENO;
	if (command->redir_out)
		fd_out = command->redir_out->fd_out;
	core = get_core();
	current_var = core->env_vars;
	while (current_var != NULL)
	{
		if (current_var->value != NULL)
			print_var(current_var->key, current_var->value, fd_out);
		current_var = current_var->next;
	}
}
