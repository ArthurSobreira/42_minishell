/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:42:44 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/07 18:48:25 by phenriq2         ###   ########.fr       */
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

t_token	*list_files(void)
{
	DIR				*dir;
	struct dirent	*entry;
	t_token			*tkn;

	dir = opendir(".");
	tkn = NULL;
	if (!dir)
	{
		perror("diropen");
		return (NULL);
	}
	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		splited_add_back(&tkn, new_token(ft_strdup(entry->d_name)));
	}
	closedir(dir);
	return (tkn);
}

t_bool	last_ocurrence(char *str, char *delimiter)
{
	int	index;

	index = ft_strlen(str) - ft_strlen(delimiter);
	if (ft_strncmp(str + index, delimiter, ft_strlen(delimiter)) == 0)
		return (TRUE);
	return (FALSE);
}

t_token	*initial_wildcard(char *wildcard, t_token *files)
{
	char	*temp;
	t_token	*new;

	temp = ft_substr(wildcard, 1, ft_strlen(wildcard));
	new = NULL;
	if (ft_strlen(temp) == 0)
		return (NULL);
	while (files->next)
	{
		if (last_ocurrence(files->value, temp) == TRUE)
		{
			splited_add_back(&new, new_token(files->value));
			files = files->next;
		}
		files = files->next;
	}
	free(temp);
	return (new);
}

t_token	*end_wildcard(char *wildcard, t_token *files)
{
	char	*temp;
	t_token	*new;

	temp = ft_substr(wildcard, 0, ft_strlen(wildcard) - 1);
	new = NULL;
	if (ft_strlen(temp) == 0)
		return (NULL);
	while (files->next)
	{
		if (ft_strncmp(files->value, temp, ft_strlen(temp)) == 0)
			splited_add_back(&new, new_token(files->value));
		files = files->next;
	}
	free(temp);
	return (new);
}

t_token	*tlist_compare(t_token *last, t_token *first)
{
	t_token	*temp;
	t_token	*current1;
	t_token	*current2;

	temp = NULL;
	current1 = first;
	while (current1)
	{
		current2 = last;
		while (current2)
		{
			if (ft_strncmp(current1->value, current2->value,
					ft_strlen(current1->value)) == 0)
				splited_add_back(&temp, new_token(current1->value));
			current2 = current2->next;
		}
		current1 = current1->next;
	}
	return (temp);
}

t_token	*analize_wildcard(t_token *files, char *wildcard)
{
	t_token	*temp;
	t_token	*first;
	t_token	*last;

	temp = NULL;
	first = NULL;
	last = NULL;
	if (wildcard[0] == '*')
		first = initial_wildcard(wildcard, files);
	if (wildcard[ft_strlen(wildcard) - 1] == '*')
		last = end_wildcard(wildcard, files);
	temp = tlist_compare(last, first);
	print_token(temp);
	return (NULL);
}

void	expand_wildcard(void)
{
	t_token	*tkn;
	char	**oi;

	t_token	*next_token;
	t_token	*files;
	tkn = find_wild();
	if (!tkn)
		return ;
	oi = ft_split(tkn->value, '*');
	print_matrix(oi);
	next_token = tkn->next;
	tkn->next = NULL;
	files = list_files();
	analize_wildcard(files, tkn->value);
}
