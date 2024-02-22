/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:16:51 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/22 09:30:00 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

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

t_bool	is_relative_path(char *cmd_name)
{
	if (cmd_name[0] == '.' && cmd_name[1] == '/')
		return (TRUE);
	if (cmd_name[0] == '.' && cmd_name[1] == '.' && cmd_name[2] == '/')
		return (TRUE);
	return (FALSE);
}
