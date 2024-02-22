/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:16:52 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/22 12:07:23 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear_token(void)
{
	t_minishell	*core;
	t_token		*tmp;

	core = get_core();
	if (core->token_list == NULL)
		return ;
	while (core->token_list)
	{
		tmp = core->token_list->next;
		ft_free(core->token_list->value);
		ft_free(core->token_list);
		core->token_list = tmp;
	}
	core->token_list = NULL;
}

void	ft_clear_env_vars(void)
{
	t_minishell	*core;
	t_var		*tmp;

	core = get_core();
	if (core->env_vars == NULL)
		return ;
	while (core->env_vars)
	{
		tmp = core->env_vars->next;
		ft_free(core->env_vars->key);
		ft_free(core->env_vars->value);
		ft_free(core->env_vars);
		core->env_vars = tmp;
	}
	core->env_vars = NULL;
}

void	ft_clear_cmd_table(void)
{
	t_minishell	*core;
	size_t		index;

	core = get_core();
	index = 0;
	if (core->cmd_table == NULL)
		return ;
	while (index <= core->pipe_count)
	{
		ft_free(core->cmd_table[index].cmd);
		if (core->cmd_table[index].args != NULL)
			ft_free_matrix(core->cmd_table[index].args);
		if (core->cmd_table[index].envp != NULL)
			ft_free_matrix(core->cmd_table[index].envp);
		ft_clear_redir_in(&core->cmd_table[index].redir_in);
		ft_clear_redir_out(&core->cmd_table[index].redir_out);
		index++;
	}
	ft_free(core->cmd_table);
	core->cmd_table = NULL;
}

void	free_variables(char *var, char **split_var)
{
	if (var != NULL)
		free(var);
	if (split_var != NULL)
		ft_free_matrix(split_var);
}

void	remove_token(t_token **token_list, t_token *target_tkn)
{
	t_token	*current_tkn;

	current_tkn = *token_list;
	while (current_tkn)
	{
		if (current_tkn == target_tkn)
		{
			if (current_tkn->prev)
				current_tkn->prev->next = current_tkn->next;
			else
				*token_list = current_tkn->next;
			if (current_tkn->next)
				current_tkn->next->prev = current_tkn->prev;
			ft_free(current_tkn->value);
			ft_free(current_tkn);
			break ;
		}
		current_tkn = current_tkn->next;
	}
}
