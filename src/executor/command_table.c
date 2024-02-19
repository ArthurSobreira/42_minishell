/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:03:22 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/19 17:37:03 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_executor(void)
{
	t_minishell	*core;
	
	core = get_core();
	core->cmd_table = malloc(sizeof(t_cmd *) * core->pipe_count + 1);
	if (core->pipe_count == 0)
	{
		core->cmd_table[0] = init_cmd();
		handle_redirects(core->cmd_table[0]);
		core->cmd_table[0]->cmd = get_command();
		
		printf("Command: %s\n", core->cmd_table[0]->cmd);
		print_token(get_core()->token_list);

		// print_redir_in(core->cmd_table->redir_in);
		// print_redir_out(core->cmd_table->redir_out);

		// remove_unnecessary_redir_in(&core->cmd_table->redir_in);
		// remove_unnecessary_redir_out(&core->cmd_table->redir_out);

		// printf("After remove unnecessary\n");

		// print_redir_in(core->cmd_table->redir_in);
		// print_redir_out(core->cmd_table->redir_out);

		// print_token(get_core()->token_list);

		// exec_single_cmd();
	}
}

// void 	create_cmd_table(void)
// {
// 	t_token		*current_tkn;
// 	t_cmd		*cmd;
// 	int			pipe_count;

// 	pipe_count = count_pipes();
// 	get_core()->pipe_count = pipe_count;
// 	current_tkn = get_core()->token_list;
// 	while (current_tkn)
// 	{
// 		cmd = init_cmd();
// 		if (current_tkn->type == TOKEN_PIPE)
// 			current_tkn = current_tkn->next;
// 		cmd->cmd = ft_strdup(current_tkn->value);
// 		cmd->args = create_args(current_tkn);
// 		cmd->envp = create_envp();
// 		cmd->redir_in = NULL;
// 		cmd->redir_out = NULL;
// 		add_cmd_to_table(cmd);
// 		current_tkn = current_tkn->next;
// 	}
// }

int	count_pipes(void)
{
	t_token		*current_tkn;
	int			pipe_count;

	current_tkn = get_core()->token_list;
	pipe_count = 0;
	while (current_tkn)
	{
		if (current_tkn->type == TOKEN_PIPE)
			pipe_count++;
		current_tkn = current_tkn->next;
	}
	return (pipe_count);
}