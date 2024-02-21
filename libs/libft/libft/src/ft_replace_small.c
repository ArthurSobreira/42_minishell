/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 08:48:26 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/20 15:55:26 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strstr_true(const char *big, const char *little, t_replace *rp)
{
	int	counter;
	int	index;

	counter = rp->start;
	if (!*little)
		return ((char *)big);
	while (big[counter] && counter < rp->end)
	{
		if (!big[counter])
			break ;
		index = 0;
		while (big[counter + index] && little[index] && big[counter
				+ index] == little[index])
			index++;
		if (!little[index])
		{
			rp->start += counter;
			return ((char *)&big[counter]);
		}
		counter++;
	}
	return (NULL);
}

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

char	*ft_replace_small(char *str, char *old, char *new, t_replace *rp)
{
	char	*result;
	char	*ptr;

	if (ft_strlen(old) == 0)
		return (ft_strdup(str));
	if (rp->end == rp->start)
		return (ft_strdup(str));
	result = ft_strdup(str);
	ptr = result;
	while (*ptr)
	{
		ptr = ft_strstr_true(ptr, old, rp);
		if (!ptr)
			break ;
		result = replace_occurrence(result, ptr, old, new);
		ptr = result + ft_strlen(new);
	}
	free(str);
	return (result);
}
