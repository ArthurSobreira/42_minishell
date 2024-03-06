/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 08:48:26 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/06 16:01:22 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*replace_occurrence(char *result, char *ptr, char *old, char *new)
{
	size_t	len;
	char	*subtemp;
	char	*tmp;

	len = ptr - result;
	subtemp = ft_substr(result, 0, len);
	tmp = ft_strjoin(subtemp, new);
	free(subtemp);
	subtemp = ft_strjoin(tmp, ptr + ft_strlen(old));
	free(result);
	free(tmp);
	return (subtemp);
}

char	*ft_replace_quotes(char *str, char *old, char *new)
{
	char	*result;
	char	*ptr;
	int		i;

	i = 0;
	if (ft_strlen(old) == 0)
		return (ft_strdup(str));
	result = ft_strdup(str);
	ptr = result;
	while (*ptr)
	{
		ptr = ft_strstr_quotes(ptr, old);
		if (!ptr)
			break ;
		i = ptr - result;
		result = replace_occurrence(result, ptr, old, new);
		ptr = result + ft_strlen(new) + i;
	}
	free(str);
	return (result);
}
