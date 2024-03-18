/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:52:05 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/10 20:15:50 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	*get_core(void)
{
	static t_minishell	core;

	return (&core);
}

void	save_tty(int tty_fd)
{
	static struct termios	tty;

	if (!tty_fd)
		tcgetattr(STDIN_FILENO, &tty);
	else
		tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	*core;

	(void)argv;
	core = NULL;
	if (argc == 1)
	{
		save_tty(0);
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
