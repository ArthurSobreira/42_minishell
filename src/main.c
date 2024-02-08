/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:52:05 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/08 14:22:53 by phenriq2         ###   ########.fr       */
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

	core = NULL;
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
	return (core->exit_status);
}
