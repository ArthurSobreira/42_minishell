/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:52:05 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/31 19:01:47 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	*get_core(void)
{
	static t_minishell	core;

	return (&core);
}

t_var	*create_var(char *key, char *value)
{
	t_var	*new_var;

	new_var = malloc(sizeof(t_var));
	if (!new_var)
		return (NULL);
	new_var->key = key;
	new_var->value = value;
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

void	get_env_vars(void)
{
	t_minishell	*core;
	char		**splitted_var;
	t_var		*current_var;
	size_t		index;
	
	index = 0;
	core = get_core();
	while (core->envp[index] != NULL)
	{
		splitted_var = ft_split(core->envp[index], '=');
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

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	*core;

	(void)argv;
	if (argc == 1)
	{
		core = init_minishell(envp);
		clear_prompt();
		print_ascii();
		get_env_vars();
		prompt_loop(core);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
