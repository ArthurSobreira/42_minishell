/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:34:19 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/10 18:53:42 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	end(const char *word, const char *subwildcard)
{
	char	*end;
	size_t	lens[2];

	lens[0] = ft_strlen(word);
	lens[1] = ft_strlen(subwildcard);
	if (lens[1] > lens[0])
		return (0);
	end = (char *)word;
	end += lens[0] - lens[1];
	if (!ft_strcmp(end, subwildcard))
		return (1);
	return (0);
}

int	comparison(const char *word, const char **substrings, int comp_type)
{
	const char	*start;
	int			begin_ok;

	start = word;
	begin_ok = 0;
	while (*substrings)
	{
		start = ft_strnstr(start, *substrings, ft_strlen(start));
		if (!start)
			return (0);
		if (!begin_ok && ((comp_type == NONE || comp_type == END)
				|| start == word))
			begin_ok = 1;
		if (begin_ok)
			start += ft_strlen(*(substrings++));
		else
			return (0);
	}
	if (comp_type >= END)
		return (end(word, *(--substrings)));
	return (1);
}

void	define_substrings(char ***substrings, const char *wildcard,
		int *comp_type)
{
	*substrings = ft_split(wildcard, '*');
	*comp_type = NONE;
	if (wildcard[0] != '*')
		*comp_type += START;
	if (wildcard[ft_strlen(wildcard) - 1] != '*')
		*comp_type += END;
}

t_bool	check_ambiguous(t_token *current_tkn, t_token *wd_list, size_t i)
{
	if (current_tkn->prev)
	{
		if ((current_tkn->prev->type == TOKEN_REDIRECT || \
			current_tkn->prev->type == TOKEN_REDIRECT_REVERSE || \
			current_tkn->prev->type == TOKEN_APPEND) && \
			(count_tokens(wd_list) > 1))
		{
			ft_file_error(current_tkn->value, "ambiguous redirect\n", \
				EXIT_FAILURE, i);
			free_token_wildcard(wd_list);
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	verify_here_doc(t_token **token, t_token *next_tmp)
{
	if ((*token)->prev && (*token)->prev->type == TOKEN_HERE_DOC)
	{
		*token = next_tmp;
		return (TRUE);
	}
	return (FALSE);
}
