/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:41 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/22 12:54:16 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_var(char *key, char *value)
{
	t_var	*var;

	var = get_core()->env_vars;
	while (var)
	{
		if (ft_strcmp(var->key, key) == 0)
		{
			var->value = ft_replace(var->value, var->value, value);
			free(value);
			return ;
		}
		var = var->next;
	}
}

void	change_directory(t_cmd *command)
{
	char	*new_dir;
	char	*current_dir;

	if (ft_matrix_len(command->args) > 2)
	{
		ft_putendl_fd("cd: too many arguments", STDERR_FILENO);
		return ;
	}
	if (ft_matrix_len(command->args) == 1)
		garbage_add(new_dir = get_var_value("HOME"));
	else
		garbage_add(new_dir = ft_strdup(command->args[1]));
	current_dir = getcwd(NULL, 0);
	if (chdir(new_dir) == -1)
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putendl_fd(strerror(2), 2);
		free(current_dir);
	}
	else
	{
		set_var("OLDPWD", current_dir);
		set_var("PWD", getcwd(NULL, 0));
	}
}
