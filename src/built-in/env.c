/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:46 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/01 12:01:40 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_var(char *key, char *value)
{
	ft_putstr_fd(key, STDOUT_FILENO);
	ft_putstr_fd("=", STDOUT_FILENO);
	if (value)
		ft_putendl_fd(value, STDOUT_FILENO);
	else
		ft_putchar_fd('\n', STDOUT_FILENO);
}

void	print_env_variables(void)
{
	t_minishell	*core;
	t_var		*current_var;

	core = get_core();
	current_var = core->env_vars;
	while (current_var != NULL)
	{
		print_var(current_var->key, current_var->value);
		current_var = current_var->next;
	}
}
