/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:16:52 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/12 22:37:14 by arsobrei         ###   ########.fr       */
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

void	ft_clear_splited_input(void)
{
	t_minishell	*core;
	t_input		*tmp;

	core = get_core();
	if (core->splited_input == NULL)
		return ;
	while (core->splited_input)
	{
		tmp = core->splited_input->next;
		ft_free(core->splited_input->content);
		ft_free(core->splited_input);
		core->splited_input = tmp;
	}
	ft_clear_token();
}
