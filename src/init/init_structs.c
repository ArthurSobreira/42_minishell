/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:31:03 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/13 12:53:43 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_minishell(t_minishell *core)
{
	core->token_list = NULL;
	core->env_vars = NULL;
	core->cmd_list = NULL;
	core->env_vars_size = 0;
	core->exit_status = EXIT_SUCCESS;
	core->file_error = FALSE;
	core->input = NULL;
}
// core.built_in = NULL;
// core->splited_input = NULL;

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
