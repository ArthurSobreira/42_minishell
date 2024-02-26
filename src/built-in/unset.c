/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:58 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/26 17:34:08 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_var(char *key)
{
	t_var	*var;
	t_var	*prev;

	var = get_core()->env_vars;
	prev = NULL;
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
		del_var(command->args[i]);
		i++;
	}
}
