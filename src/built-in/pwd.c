/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:56 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/12 15:23:37 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_working_directory(void)
{
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
		ft_error("pwd: Cannot print the current directory\n",
			EXIT_FAILURE);
	return (current_dir);
}

void	print_working_directory(void)
{
	char	*current_dir;

	current_dir = get_working_directory();
	if (current_dir != NULL)
		ft_putendl_fd(current_dir, STDOUT_FILENO);
	ft_free_pointer((void *)&current_dir);
}
