/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:50:48 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/24 17:57:41 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

void	echo(void)
{
	t_minishell	*core;

	core = get_core();
	ft_print_list(core->splited_input);
}
