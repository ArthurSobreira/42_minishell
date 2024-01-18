/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:02:14 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/26 16:06:39 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_str;

	if (!s)
		return (0);
	len_str = ft_strlen((char *)s);
	if (start >= len_str)
		return (ft_strdup(""));
	if (len > len_str - start)
		len = len_str - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	ft_strlcpy(sub, (s + start), (len + 1));
	return (sub);
}
