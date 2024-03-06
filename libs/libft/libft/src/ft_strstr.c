/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:07:52 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/06 14:58:30 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_quotes(char *str, size_t *i)
{
	char	quote;

	quote = str[*i];
	(*i)++;
	while (str[*i] && str[*i] != quote)
		(*i)++;
}

char	*ft_strstr(const char *big, const char *little)
{
	size_t	counter;
	size_t	index;

	counter = 0;
	if (!*little)
		return ((char *)big);
	while (big[counter])
	{
		if (big[counter] == '\"' || big[counter] == '\'')
			skip_quotes((char *)big, &counter);
		if (!big[counter])
			break ;
		index = 0;
		while (big[counter + index] && little[index] && big[counter
				+ index] == little[index])
			index++;
		if (!little[index])
			return ((char *)&big[counter]);
		counter++;
	}
	return (NULL);
}
