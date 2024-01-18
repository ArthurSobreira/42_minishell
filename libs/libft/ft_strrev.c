/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:15:37 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 15:38:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *ptr)
{
	int		index;
	int		index_end;
	char	temp;

	index = 0;
	index_end = ft_strlen(ptr) - 1;
	while (index < index_end)
	{
		temp = ptr[index];
		ptr[index] = ptr[index_end];
		ptr[index_end] = temp;
		index++;
		index_end--;
	}
}
