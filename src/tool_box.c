/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:34:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/22 10:22:22 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
