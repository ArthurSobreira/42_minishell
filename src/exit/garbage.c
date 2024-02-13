/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:52 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/13 14:33:28 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	garbage_add(void *ptr)
{
	t_list	*gc;

	gc = malloc(sizeof(t_list));
	if (!gc)
		return ;
	gc->content = ptr;
	gc->next = get_core()->gc;
	get_core()->gc = gc;
}

void	clear_garbage(void)
{
	t_list	*garbage_c;
	t_list	*next;

	garbage_c = get_core()->gc;
	while (garbage_c)
	{
		next = garbage_c->next;
		ft_free(garbage_c->content);
		ft_free(garbage_c);
		garbage_c = next;
	}
	get_core()->gc = NULL;
}
