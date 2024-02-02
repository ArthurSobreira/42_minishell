/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:32:39 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/01 23:32:39 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	check_file_existence(char *file_name)
{
	if (access(file_name, F_OK) == -1)
	{
		ft_error("no such file or directory\n", EXIT_FAILURE);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	check_file_permissions(char *file_name)
{
	if (access(file_name, R_OK) == -1)
	{
		ft_error("permission denied\n", PERMISSION_ERROR);
		return (FALSE);
	}
	return (TRUE);
}
