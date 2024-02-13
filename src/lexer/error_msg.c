/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:13:35 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/13 15:06:15 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_quotes(char *str, int *i)
{
	char	quote;

	quote = str[*i];
	(*i)++;
	while (str[*i] && str[*i] != quote)
		(*i)++;
}

t_bool	exit_status_2(char *error_msg)
{
	if (ft_strcmp(error_msg, END_FILE) == 0)
		return (TRUE);
	else if (ft_strcmp(error_msg, FORBIDDEN_AND) == 0)
		return (TRUE);
	else if (ft_strcmp(error_msg, FORBIDDEN_OR) == 0)
		return (TRUE);
	else if (ft_strcmp(error_msg, FORBIDDEN_SEMICOLON) == 0)
		return (TRUE);
	else if (ft_strcmp(error_msg, FORBIDDEN_BACKGROUND) == 0)
		return (TRUE);
	else if (ft_strcmp(error_msg, FORBIDDEN_PIPE) == 0)
		return (TRUE);
	else if (ft_strcmp(error_msg, FORBIDDEN_REDIR) == 0)
		return (TRUE);
	else if (ft_strcmp(error_msg, FORBIDDEN_REDIR_REVERSE) == 0)
		return (TRUE);
	return (FALSE);
}

void	set_exit_status(char *error_msg)
{
	if (exit_status_2(error_msg))
		get_core()->exit_status = 2;
	ft_error(error_msg, get_core()->exit_status);
}
