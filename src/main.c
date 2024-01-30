/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:52:05 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/30 15:52:38 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	*get_core(void)
{
	static t_minishell	core;

	return (&core);
}

void	get_env_vars(char *envp[])
{
	t_minishell	*core;
	int			i;

	core = get_core();
	core->env_vars = NULL;
	core->env_vars_size = 0;
	i = 0;
	while (envp[i])
	{
		ft_lstadd_back(&core->env_vars, ft_lstnew(ft_strdup(envp[i])));
		core->env_vars_size++;
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	*core;

	(void)argv;
	(void)envp;
	if (argc == 1)
	{
		print_ascii();
		core = get_core();
		if (core == NULL)
			return (EXIT_FAILURE);
		built_in_array(core);
		get_env_vars(envp);
		prompt_loop(core);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
