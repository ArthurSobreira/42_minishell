/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:46 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/31 18:18:14 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	print_var(t_var *var)
// {
// 	ft_putstr_fd(var->key, STDOUT_FILENO);
// 	ft_putstr_fd("=", STDOUT_FILENO);
// 	if (var->value)
// 		ft_putendl_fd(var->value, STDOUT_FILENO);
// 	else
// 		ft_putchar_fd('\n', STDOUT_FILENO);
// }

void	print_env_variables(void)
{
	t_minishell	*core;

	core = get_core();
	while (core->env_vars->next != NULL)
	{
		printf("%s=%s\n", core->env_vars->key, core->env_vars->value);
		// ft_putstr_fd(core->env_vars->key, STDOUT_FILENO);
		// ft_putstr_fd("=", STDOUT_FILENO);
		// if (core->env_vars->value)
		// 	ft_putendl_fd(core->env_vars->value, STDOUT_FILENO);
		// else
		// 	ft_putchar_fd('\n', STDOUT_FILENO);
		core->env_vars = core->env_vars->next;
	}
}
