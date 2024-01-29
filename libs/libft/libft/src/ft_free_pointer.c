/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:52:38 by arsobrei          #+#    #+#             */
/*   Updated: 2024/01/29 09:53:26 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_pointer(void **pointer)
{
	if (*pointer)
	{
		free(*pointer);
		*pointer = NULL;
	}
}
