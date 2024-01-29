/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:56 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/29 10:17:46 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_working_directory(void)
{
	t_minishell	*core;
	char		*buffer;
	char		*current_dir;

	core = get_core();
	buffer = NULL;
	current_dir = getcwd(buffer, 0);
	if (!current_dir)
	{
		core->exits.exit_code = EXIT_FAILURE;
		core->exits.exit_msg = \
			ft_strdup("pwd: Cannot print the current directory");
	}
	else
	{
		core->exits.exit_code = EXIT_SUCCESS;
		core->exits.exit_msg = NULL;
	}
	return (current_dir);
}

void	print_working_directory(void)
{
	char	*current_dir;

	current_dir = get_working_directory();
	if (current_dir != NULL)
		ft_printf("%s\n", current_dir);
	ft_free_pointer((void *)&current_dir);
}
