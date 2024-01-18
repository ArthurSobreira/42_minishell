/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:57:18 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/04 10:13:06 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->value = value;
	new->next = 0;
	return (new);
}
