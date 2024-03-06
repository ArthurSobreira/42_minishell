/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:42:44 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/06 12:40:40 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	has_wildcard(char *str)
{
	while (*str)
	{
		if (*str == '*')
			return (TRUE);
		str++;
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
		{
			return (current_tkn);
		}
		current_tkn = current_tkn->next;
	}
	return (NULL);
}

void	list_files(void)
{
	DIR				*dir;
	struct dirent	*entry;
	t_token			*tkn;

	dir = opendir(".");
	if (!dir)
	{
		perror("diropen");
		return ;
	}
	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		splited_add_back(&tkn, new_token(ft_strdup(entry->d_name)));
	}
	closedir(dir);
}

void	expand_wildcard(void)
{
	t_token	*tkn;
	t_token	*next_token;

	tkn = find_wild();
	if (!tkn)
		return ;
	next_token = tkn->next;
	tkn->next = NULL;
	list_files();
}
