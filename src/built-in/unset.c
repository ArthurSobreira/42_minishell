/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:58 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/08 17:33:55 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	is_only_alpha(char *arg)
{
	size_t	i;

	i = 0;
	if (arg[0] == '_' && ft_isalnum(arg[1]))
		return (TRUE);
	while (arg[i])
	{
		if (!ft_isalnum(arg[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	is_valid_unset_argument(char *arg)
{
	if ((arg[0] != '_' && !ft_isalnum(arg[0])) || \
		!is_only_alpha(arg))
	{
		ft_putstr_fd("minishell: export: `", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
		get_core()->exit_status = EXIT_FAILURE;
		return (FALSE);
	}
	return (TRUE);
}

void	del_var(char *key)
{
	t_var	*var;
	t_var	*prev;

	var = get_core()->env_vars;
	prev = NULL;
	if (get_core()->env_vars_size == 0)
		return ;
	while (var)
	{
		if (ft_strcmp(var->key, key) == 0)
		{
			if (prev)
				prev->next = var->next;
			else
				get_core()->env_vars = var->next;
			free(var->key);
			free(var->value);
			free(var);
			get_core()->env_vars_size--;
			return ;
		}
		prev = var;
		var = var->next;
	}
}

void	unset(t_cmd *command)
{
	int	i;

	i = 1;
	get_core()->exit_status = EXIT_SUCCESS;
	while (command->args[i])
	{
		if (!is_valid_unset_argument(command->args[i]))
		{
			i++;
			continue ;
		}
		del_var(command->args[i]);
		i++;
	}
}
