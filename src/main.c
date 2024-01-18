/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:52:05 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/17 16:35:32 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_minishell	core;

	(void)argv;
	(void)envp;
	if (argc != 1)
		return (0);
	ft_bzero(&core, sizeof(t_minishell));
	built_in_array(&core);
	readlines(&core);
	return (0);
}
