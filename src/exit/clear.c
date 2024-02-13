/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:16:52 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/13 14:27:53 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear_token(void)
{
	t_minishell	*core;
	t_token		*tmp;

	core = get_core();
	if (core->token_list == NULL)
		return ;
	while (core->token_list)
	{
		tmp = core->token_list->next;
		ft_free(core->token_list->value);
		ft_free(core->token_list);
		core->token_list = tmp;
	}
}

void	ft_clear_env_vars(void)
{
	t_minishell	*core;
	t_var		*tmp;

	core = get_core();
	if (core->env_vars == NULL)
		return ;
	while (core->env_vars)
	{
		tmp = core->env_vars->next;
		ft_free(core->env_vars->key);
		ft_free(core->env_vars->value);
		ft_free(core->env_vars);
		core->env_vars = tmp;
	}
}
