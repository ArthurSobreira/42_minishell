/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:52:05 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/07 19:53:13 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	*get_core(void)
{
	static t_minishell	core;

	return (&core);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	*core;

	(void)argv;
	if (argc == 1)
	{
		core = get_core();
		core->envp = envp;
		clear_prompt();
		print_ascii();
		init_minishell(core);
		get_env_vars(core);
		prompt_loop(core);
	}
	return (EXIT_FAILURE);
}
