/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:52:05 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/29 10:54:38 by phenriq2         ###   ########.fr       */
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
	(void)envp;
	if (argc == 1)
	{
		print_ascii();
		core = get_core();
		if (core == NULL)
			return (EXIT_FAILURE);
		built_in_array(core);
		readlines(core);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
