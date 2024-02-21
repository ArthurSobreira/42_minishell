/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_coisas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:39:32 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/21 19:05:18 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		printf("type: %d\n", tmp->type);
		printf("value: %s\n", tmp->value);
		tmp = tmp->next;
	}
}

void	print_redir_out(t_redir_out *redir_list)
{
	t_redir_out	*current_redir;

	current_redir = redir_list;
	if (redir_list == NULL)
	{
		printf("redir_out: NULL\n");
		return ;
	}
	while (current_redir)
	{
		printf("\n-----redirect_out-----\n");
		printf("r_type: %d\n", current_redir->r_type);
		printf("redir_out: %s\n", current_redir->file_name);
		printf("fd_out: %d\n\n", current_redir->fd_out);
		current_redir = current_redir->next;
	}
}

void	print_redir_in(t_redir_in *redir_list)
{
	t_redir_in	*current_redir;

	current_redir = redir_list;
	if (redir_list == NULL)
	{
		printf("redir_in: NULL\n");
		return ;
	}
	while (current_redir)
	{
		printf("\n-----redirect_in-----\n");
		printf("r_type: %d\n", current_redir->r_type);
		if (current_redir->here_doc)
			printf("has here_doc\n");
		else
			printf("no here_doc\n");
		printf("redir_in: %s\n", current_redir->file_name);
		printf("fd_in: %d\n\n", current_redir->fd_in);
		current_redir = current_redir->next;
	}
}

void	print_cmd_table(t_cmd *cmd_table)
{
	size_t	index;
	size_t	args_index;

	index = 0;
	while (index <= get_core()->pipe_count)
	{
		printf("\npid: %d\n", cmd_table[index].pid);
		printf("cmd: %s\n", cmd_table[index].cmd);
		printf("is_builtin: %d\n", cmd_table[index].is_builtin);
		if (cmd_table[index].args != NULL)
		{
			args_index = 0;
			while (cmd_table[index].args[args_index] != NULL)
			{
				printf("arg[%zu] = %s\n", args_index, \
					cmd_table[index].args[args_index]);
				args_index++;
			}
		}
		else
			printf("args: NULL\n");
		print_redir_in(cmd_table[index].redir_in);
		print_redir_out(cmd_table[index].redir_out);
		index++;
	}
}
