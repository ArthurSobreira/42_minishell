/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:31:03 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/05 12:01:52 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_minishell(t_minishell *core)
{
	ft_bzero(&core->error_check.file_error, MAX_PIPELINES);
	core->token_list = NULL;
	core->env_vars = NULL;
	core->cmd_table = NULL;
	core->env_vars_size = 0;
	core->pipe_count = 0;
	core->pipe_fd[0] = -1;
	core->pipe_fd[1] = -1;
	core->exit_status = EXIT_SUCCESS;
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
		cmd_table[index].proc_type = -1;
		cmd_table[index].is_builtin = FALSE;
		cmd_table[index].redir_in = NULL;
		cmd_table[index].redir_out = NULL;
		cmd_table[index].cmd = NULL;
		cmd_table[index].args = NULL;
		cmd_table[index].envp = NULL;
		cmd_table[index].cmd_pos = index;
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
