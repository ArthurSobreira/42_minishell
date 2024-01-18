/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:33:21 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/14 15:52:10 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	word;

	word = 0;
	while (*s)
	{
		if (*s != c)
		{
			word++;
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	t_var	spl;

	spl.i = 0;
	if (!s)
		return (0);
	spl.s_string = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!spl.s_string)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				spl.len_subs = ft_strlen(s);
			else
				spl.len_subs = ft_strchr(s, c) - s;
			spl.s_string[spl.i] = ft_substr(s, 0, spl.len_subs);
			spl.i++;
			s += spl.len_subs;
		}
	}
	spl.s_string[spl.i] = NULL;
	return (spl.s_string);
}
