/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:31:03 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/06 15:12:40 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_minishell(t_minishell *core)
{
	core->token_list = NULL;
	core->splited_input = NULL;
	core->env_vars = NULL;
	core->cmd_list = NULL;
	core->env_vars_size = 0;
	// core.built_in = NULL;
	core->input = NULL;
}

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	cmd->executable = NULL;
	cmd->arguments = NULL;
	cmd->redir_in = NULL;
	cmd->redir_out = NULL;
	return (cmd);
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
