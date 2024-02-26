/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:41 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/26 16:46:59 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	validate_args(t_minishell *core, t_cmd *command)
{
	if (ft_matrix_len(command->args) > 2)
	{
		ft_putendl_fd("minishell: cd: too many arguments", STDERR_FILENO);
		core->exit_status = EXIT_FAILURE;
		return (FALSE);
	}
	return (TRUE);
}

static void	set_var(char *key, char *value)
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

	if (!validate_args(get_core(), command))
		return ;
	if (ft_matrix_len(command->args) == 1)
		garbage_add(new_dir = get_var_value("HOME"));
	else
		garbage_add(new_dir = ft_strdup(command->args[1]));
	current_dir = getcwd(NULL, 0);
	if (chdir(new_dir) == -1)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		free(current_dir);
		get_core()->exit_status = EXIT_FAILURE;
	}
	else
	{
		set_var("OLDPWD", current_dir);
		set_var("PWD", getcwd(NULL, 0));
	}
}
