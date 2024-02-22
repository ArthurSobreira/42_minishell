/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:03:22 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/22 18:14:05 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_cmd_table(void)
{
	t_minishell	*core;
	t_token		*current_tkn;
	size_t		index;

	index = -1;
	core = get_core();
	core->pipe_count = count_pipes();
	core->cmd_table = init_cmd_table();
	if (core->cmd_table == NULL)
		return ;
	while (++index <= core->pipe_count)
	{
		handle_redirects(&core->cmd_table[index], index);
		remove_unnecessary_redir_in(&core->cmd_table[index].redir_in);
		remove_unnecessary_redir_out(&core->cmd_table[index].redir_out);
		current_tkn = core->token_list;
		if (check_for_inconsistencies(current_tkn, index))
			continue ;
		if (current_tkn != NULL)
			fill_command_node(current_tkn, index);
	}
	print_cmd_table(core->cmd_table);
}

t_bool	check_for_inconsistencies(t_token *current_tkn, size_t index)
{
	t_minishell	*core;

	core = get_core();
	if (current_tkn && current_tkn->type == TOKEN_PIPE)
	{
		remove_token_and_redir(current_tkn, index);
		current_tkn = core->token_list;
		return (TRUE);
	}
	if (core->error_check.file_error[index])
	{
		core->error_check.cmd_error = TRUE;
		while (current_tkn && current_tkn->type != TOKEN_PIPE)
		{
			remove_token_and_redir(current_tkn, index);
			current_tkn = core->token_list;
		}
		return (TRUE);
	}
	return (FALSE);
}

void	fill_command_node(t_token *current_tkn, size_t index)
{
	t_minishell	*core;

	core = get_core();
	if (is_builtin(current_tkn->value))
	{
		core->cmd_table[index].is_builtin = TRUE;
		core->cmd_table[index].cmd = ft_strdup(current_tkn->value);
		ft_clear_redir_in(&core->cmd_table[index].redir_in);
		remove_token(&core->token_list, current_tkn);
	}
	else
		core->cmd_table[index].cmd = get_command();
	core->cmd_table[index].args = \
		get_arguments(core->cmd_table[index].cmd);
	core->cmd_table[index].envp = get_envp(core->env_vars);
}

char	**get_arguments(char *cmd_name)
{
	t_token		*current_tkn;
	t_token		*next_tkn;
	size_t		index;
	char		**args;

	index = 0;
	current_tkn = get_core()->token_list;
	args = malloc(sizeof(char *) * (count_args(current_tkn) + 2));
	if (!args)
		return (NULL);
	args[index++] = ft_strdup(cmd_name);
	while (current_tkn && current_tkn->type != TOKEN_PIPE)
	{
		next_tkn = current_tkn->next;
		args[index] = ft_strdup(current_tkn->value);
		remove_token(&get_core()->token_list, current_tkn);
		current_tkn = next_tkn;
		index++;
	}
	args[index] = NULL;
	return (args);
}

char	**get_envp(t_var *env_vars)
{
	t_var		*current_var;
	size_t		index;
	char		**envp;
	char		*key;

	current_var = env_vars;
	index = 0;
	envp = malloc(sizeof(char *) * (get_core()->env_vars_size + 1));
	while (current_var != NULL)
	{
		key = ft_strjoin(current_var->key, "=");
		if (current_var->value)
			envp[index] = ft_strjoin(key, current_var->value);
		else
			envp[index] = ft_strdup(key);
		free(key);
		current_var = current_var->next;
		index++;
	}
	envp[index] = NULL;
	return (envp);
}
