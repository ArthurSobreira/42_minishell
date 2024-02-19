/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:31:03 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/15 18:31:01 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_minishell(t_minishell *core)
{
	core->token_list = NULL;
	core->env_vars = NULL;
	core->cmd_table = NULL;
	core->env_vars_size = 0;
	core->exit_status = EXIT_SUCCESS;
	core->error_check.file_error = FALSE;
	core->input = NULL;
}

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	cmd->cmd = NULL;
	cmd->args = NULL;
	cmd->envp = NULL;
	cmd->pid = -1;
	cmd->is_builtin = FALSE;
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
