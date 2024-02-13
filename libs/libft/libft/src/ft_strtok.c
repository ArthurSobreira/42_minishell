/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:58:25 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/10 18:12:32 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*last = NULL;
	char		*token;
	size_t		len;

	if (str != NULL)
		last = str;
	if (last == NULL || *last == '\0')
		return (NULL);
	last += ft_strspn(last, delim);
	if (*last == '\0')
		return (NULL);
	len = ft_strcspn(last, delim);
	token = (char *)malloc(len + 1);
	if (token == NULL)
		return (NULL);
	ft_strncpy(token, last, len);
	token[len] = '\0';
	last += len;
	return (token);
}
