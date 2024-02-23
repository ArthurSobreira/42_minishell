/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_table_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:39:30 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/22 15:39:25 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	count_args(t_token *token_list)
{
	t_token		*current_tkn;
	int			args_count;

	current_tkn = token_list;
	args_count = 0;
	while (current_tkn && current_tkn->type != TOKEN_PIPE)
	{
		args_count++;
		current_tkn = current_tkn->next;
	}
	return (args_count);
}

void	remove_token_and_redir(t_token *token, size_t index)
{
	t_minishell	*core;

	core = get_core();
	remove_token(&core->token_list, token);
	ft_clear_redir_in(&core->cmd_table[index].redir_in);
	ft_clear_redir_out(&core->cmd_table[index].redir_out);
}

t_bool	is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "cd"))
		return (TRUE);
	if (!ft_strcmp(cmd, "echo"))
		return (TRUE);
	if (!ft_strcmp(cmd, "env"))
		return (TRUE);
	if (!ft_strcmp(cmd, "exit"))
		return (TRUE);
	if (!ft_strcmp(cmd, "export"))
		return (TRUE);
	if (!ft_strcmp(cmd, "pwd"))
		return (TRUE);
	if (!ft_strcmp(cmd, "unset"))
		return (TRUE);
	return (FALSE);
}
