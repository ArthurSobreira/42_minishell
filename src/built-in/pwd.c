/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:56 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/24 14:49:14 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_working_directory(void)
{
	char	buffer[MAX_PATH_LEN];
	char	*pwd;

	pwd = getcwd(buffer, MAX_PATH_LEN);
	return (pwd);
}

void	print_working_directory(t_minishell *core)
{
	char	*pwd;

	(void)core;
	pwd = get_working_directory();
	ft_printf("%s\n", pwd);
}
