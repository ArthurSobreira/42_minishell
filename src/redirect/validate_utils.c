/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:56:34 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/06 18:56:53 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	validate_directory_exists(char *path)
{
	struct stat	statbuf;
	char		*last_slash;
	int			i;

	i = ft_strrchr(path, '/') - path;
	last_slash = ft_substr(path, 0, i);
	if (stat(last_slash, &statbuf) == -1)
	{
		free(last_slash);
		return (FALSE);
	}
	if (S_ISDIR(statbuf.st_mode))
	{
		free(last_slash);
		return (TRUE);
	}
	free(last_slash);
	return (FALSE);
}

t_bool	check_file_exists(char *file_name)
{
	if (access(file_name, F_OK) == -1)
		return (FALSE);
	return (TRUE);
}

t_bool	check_file_readable(char *file_name)
{
	if (access(file_name, R_OK) == -1)
		return (FALSE);
	return (TRUE);
}

t_bool	check_file_writable(char *file_name)
{
	if (access(file_name, W_OK) == -1)
		return (FALSE);
	return (TRUE);
}

t_bool	check_file_executable(char *file_name)
{
	if (access(file_name, X_OK) == -1)
		return (FALSE);
	return (TRUE);
}
