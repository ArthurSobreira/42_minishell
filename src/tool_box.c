/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_bix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:34:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/18 10:45:41 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lstrip(char **str)
{
	char	*tmp;

	tmp = *str;
	while (*tmp == ' ')
		tmp++;
	*str = tmp;
}

void	ft_rstrip(char **str)
{
	char	*tmp;

	tmp = *str;
	while (*tmp)
		tmp++;
	tmp--;
	while (*tmp == ' ')
		tmp--;
	tmp++;
	*tmp = '\0';
	*str = tmp;
}
