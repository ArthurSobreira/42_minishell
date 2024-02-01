/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:14:33 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/01 12:19:05 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_env_vars(t_minishell *core)
{
	char		**splitted_var;
	char		**envp;
	t_var		*current_var;
	size_t		index;

	envp = core->envp;
	splitted_var = NULL;
	current_var = NULL;
	index = 0;
	while (envp[index] != NULL)
	{
		splitted_var = ft_split(envp[index], '=');
		current_var = create_var(splitted_var[0], splitted_var[1]);
		if (current_var)
		{
			if (core->env_vars == NULL)
				core->env_vars = current_var;
			else
				find_last_var(core->env_vars)->next = current_var;
			core->env_vars_size++;
		}
		ft_free_matrix(splitted_var);
		index++;
	}
}

t_var	*create_var(char *key, char *value)
{
	t_var	*new_var;

	new_var = malloc(sizeof(t_var));
	if (!new_var)
		return (NULL);
	if (key)
		new_var->key = ft_strdup(key);
	else
		new_var->key = NULL;
	if (value)
		new_var->value = ft_strdup(value);
	else
		new_var->value = NULL;
	new_var->next = NULL;
	return (new_var);
}

t_var	*find_last_var(t_var *var)
{
	if (!var)
		return (NULL);
	while (var->next != NULL)
		var = var->next;
	return (var);
}
