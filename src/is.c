/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:59 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/24 15:28:35 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ispipe(int c)
{
	return (c == '|');
}

t_bool	issemicolon(int c)
{
	return (c == ';');
}

t_bool	isredir(int c)
{
	return (c == '>' || c == '<');
}

t_bool	isbackground(int c)
{
	return (c == '&');
}

t_bool	isnull(int c)
{
	return (c == '\0');
}
