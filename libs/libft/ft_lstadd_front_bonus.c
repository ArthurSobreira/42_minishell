/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:34:57 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/12 18:14:55 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (!new_node)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	new_node->next = *lst;
	*lst = new_node;
}
