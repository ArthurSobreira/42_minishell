/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:31:03 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/20 12:31:36 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_minishell(t_minishell *core)
{
	core->token_list = NULL;
	core->env_vars = NULL;
	core->cmd_table = NULL;
	core->env_vars_size = 0;
	core->pipe_count = 0;
	core->exit_status = EXIT_SUCCESS;
	core->error_check.file_error = FALSE;
	core->input = NULL;
}

t_cmd	*init_cmd_table(void)
{
	t_minishell	*core;
	t_cmd		*cmd_table;
	size_t		index;

	core = get_core();
	cmd_table = malloc(sizeof(t_cmd) * (core->pipe_count + 1));
	if (cmd_table == NULL)
		return (NULL);
	index = 0;
	while (index <= core->pipe_count)
	{
		cmd_table[index].pid = -1;
		cmd_table[index].is_builtin = FALSE;
		cmd_table[index].redir_in = NULL;
		cmd_table[index].redir_out = NULL;
		cmd_table[index].cmd = NULL;
		cmd_table[index].args = NULL;
		cmd_table[index].envp = NULL;
		index++;
	}
	return (cmd_table);
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
