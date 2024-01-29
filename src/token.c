/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:26:04 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/29 11:23:28 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_list(t_list *list)
{
	while (list)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
}

void	tokenization(void)
{
	t_minishell *core;
	int i;

	core = get_core();
	i = 0;
}