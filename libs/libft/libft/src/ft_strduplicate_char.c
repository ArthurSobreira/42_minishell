/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strduplicate_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:19:13 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/06 16:19:29 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strduplicate_char(char c)
{
	char	*str;

	str = (char *)malloc(3);
	str[0] = c;
	str[1] = c;
	str[2] = '\0';
	return (str);
}
