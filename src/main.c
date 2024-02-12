/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:52:05 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/12 17:49:48 by phenriq2         ###   ########.fr       */
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
	core = NULL;
	core = (t_minishell *){0};
	core = get_core();
	if (argc == 1)
	{
		core->envp = envp;
		clear_prompt();
		print_ascii();
		get_env_vars(core);
		prompt_loop();
	}
	return (core->exit_status);
}

// init_minishell(core);