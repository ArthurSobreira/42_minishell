/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_table_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:39:30 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/20 18:00:53 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*validate_cmd_path(char *cmd_name)
{
	size_t	index;
	char	*cmd_path;
	char	*cmd_with_path;
	char	**split_path;

	index = 0;
	cmd_path = NULL;
	cmd_with_path = NULL;
	split_path = get_split_path();
	while (split_path[index] != NULL)
	{
		cmd_path = ft_strjoin(split_path[index], "/");
		cmd_with_path = ft_strjoin(cmd_path, cmd_name);
		free(cmd_path);
		if (access(cmd_with_path, F_OK | X_OK) == 0)
		{
			free_variables(cmd_name, split_path);
			return (cmd_with_path);
		}
		free(cmd_with_path);
		index++;
	}
	free_variables(NULL, split_path);
	return (NULL);
}

char	**get_split_path(void)
{
	t_var	*env_vars;
	char	**split_path;

	env_vars = get_core()->env_vars;
	split_path = NULL;
	while (env_vars)
	{
		if (!ft_strcmp(env_vars->key, "PATH"))
		{
			split_path = ft_split(env_vars->value, ':');
			break ;
		}
		env_vars = env_vars->next;
	}
	return (split_path);
}

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
