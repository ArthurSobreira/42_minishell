/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:42:44 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/10 18:53:15 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	has_wildcard(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '*')
			return (TRUE);
		index++;
	}
	return (FALSE);
}

t_token	*find_wild(void)
{
	t_token	*current_tkn;

	current_tkn = get_core()->token_list;
	while (current_tkn)
	{
		if (has_wildcard(current_tkn->value))
			return (current_tkn);
		current_tkn = current_tkn->next;
	}
	return (NULL);
}

t_token	*wild_exec(char *str, t_token *new, DIR *dir, char **substrings)
{
	struct dirent	*entry;
	const char		*compare;
	int				comp_type;

	compare = str;
	dir = opendir(".");
	if (!dir)
		return (NULL);
	define_substrings(&substrings, compare, &comp_type);
	if (!substrings)
		return (NULL);
	entry = readdir(dir);
	while (entry)
	{
		if (*(char *)entry->d_name != '.' && \
			comparison(((const char *)entry->d_name), (const char **)substrings,
				comp_type))
			splited_add_back(&new, new_token(ft_strdup(entry->d_name)));
		entry = readdir(dir);
	}
	closedir(dir);
	ft_free_matrix(substrings);
	if (!new)
		splited_add_back(&new, new_token(ft_strdup(compare)));
	return (new);
}

void	handle_wd_list(t_token *token, t_token *nxt, t_token *new_list, \
	t_token *temp)
{
	if (nxt)
		splited_add_back(&new_list, nxt);
	if (token->prev)
	{
		token->prev->next = new_list;
		new_list->prev = token->prev;
	}
	else
		get_core()->token_list = new_list;
	free_token(temp);
}

void	expand_wildcard(void)
{
	t_token	*token;
	t_token	*new_list;
	t_token	*next_tmp;
	t_token	*tmp;
	size_t	pipe_count;

	token = get_core()->token_list;
	pipe_count = 0;
	while (token)
	{
		if (token->type == TOKEN_PIPE)
			pipe_count++;
		next_tmp = token->next;
		if (has_wildcard(token->value))
		{
			if (verify_here_doc(&token, next_tmp))
				continue ;
			tmp = token;
			new_list = wild_exec(token->value, NULL, NULL, NULL);
			if (check_ambiguous(token, new_list, pipe_count))
				return ;
			handle_wd_list(token, next_tmp, new_list, tmp);
		}
		token = next_tmp;
	}
}
