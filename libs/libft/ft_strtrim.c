/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:49:56 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 15:38:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	end;
	unsigned int	start;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while ((s1[start]) && (ft_strchr(set, s1[start])))
		start++;
	end = ft_strlen(s1);
	while ((end) && (ft_strchr(set, s1[end - 1])))
		end--;
	return (ft_substr(s1, start, end - start));
}
