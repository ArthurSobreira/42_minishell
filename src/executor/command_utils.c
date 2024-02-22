/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:48:21 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/22 18:14:58 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_command(void)
{
	t_token		*current_tkn;
	t_token		*next_tkn;
	char		*cmd_name;
	char		*cmd_path;

	current_tkn = get_core()->token_list;
	next_tkn = current_tkn->next;
	cmd_name = ft_strdup(current_tkn->value);
	if (access(cmd_name, F_OK | X_OK) == 0)
	{
		remove_token(&get_core()->token_list, current_tkn);
		return (cmd_name);
	}
	cmd_path = validate_cmd_path(cmd_name);
	remove_token(&get_core()->token_list, current_tkn);
	if (cmd_path == NULL)
		return (cmd_name);
	return (cmd_path);
}

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
