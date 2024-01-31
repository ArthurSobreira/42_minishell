/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:31:03 by arsobrei          #+#    #+#             */
/*   Updated: 2024/01/31 14:11:23 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	*init_minishell(char *envp[])
{
	t_minishell	*core;

	core = get_core();
	core->token_list = NULL;
	core->splited_input = NULL;
	core->env_vars = NULL;
	core->env_vars_size = 0;
	// core.built_in = NULL;
	core->input = NULL;
	core->envp = envp;
	core->exits.exit_code = 0;
	core->exits.exit_msg = NULL;
	return (core);
}

t_prompt	init_prompt(void)
{
	t_prompt	prompt_data;

	prompt_data.user = NULL;
	prompt_data.hostname = NULL;
	prompt_data.current_dir = NULL;
	prompt_data.prompt = NULL;
	return (prompt_data);
}
