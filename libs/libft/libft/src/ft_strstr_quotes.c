/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:07:52 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/10 11:51:53 by phenriq2         ###   ########.fr       */
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

char	*ft_strstr_quotes(const char *big, const char *little)
{
	size_t	counter;
	size_t	index;
	t_bool	in_quote;

	counter = 0;
	in_quote = FALSE;
	if (!*little)
		return ((char *)big);
	while (big[counter])
	{
		if (big[counter] == '\"')
			in_quote = !in_quote;
		if (big[counter] == '\'' && !in_quote)
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
