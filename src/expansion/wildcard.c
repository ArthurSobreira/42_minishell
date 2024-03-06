// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   wildcard.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/03/04 11:42:44 by phenriq2          #+#    #+#             */
// /*   Updated: 2024/03/06 17:27:45 by phenriq2         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minishell.h"

// t_bool	has_wildcard(char *str)
// {
// 	int	index;

// 	index = 0;
// 	while (str[index])
// 	{
// 		if (str[index] == '*')
// 			return (TRUE);
// 		index++;
// 	}
// 	return (FALSE);
// }

// t_token	*find_wild(void)
// {
// 	t_token	*current_tkn;

// 	current_tkn = get_core()->token_list;
// 	while (current_tkn)
// 	{
// 		if (has_wildcard(current_tkn->value))
// 			return (current_tkn);
// 		current_tkn = current_tkn->next;
// 	}
// 	return (NULL);
// }

// t_token	*list_files(void)
// {
// 	DIR				*dir;
// 	struct dirent	*entry;
// 	t_token			*tkn;

// 	dir = opendir(".");
// 	if (!dir)
// 	{
// 		perror("diropen");
// 		return (NULL);
// 	}
// 	while (1)
// 	{
// 		entry = readdir(dir);
// 		if (!entry)
// 			break ;
// 		splited_add_back(&tkn, new_token(ft_strdup(entry->d_name)));
// 	}
// 	closedir(dir);
// 	return (tkn);
// }

// t_bool	last_ocurrence(char *str, char *delimiter)
// {
// 	int	index;

// 	index = ft_strlen(str) - ft_strlen(delimiter);
// 	if (ft_strncmp(str + index, delimiter, ft_strlen(delimiter)) == 0)
// 		return (TRUE);
// 	return (FALSE);
// }

// t_token	*initial_wildcard(char *wildcard, t_token *files)
// {
// 	char	*temp;
// 	t_token	*next;

// 	(void)files;
// 	temp = ft_substr(wildcard, 1, ft_strlen(wildcard));
// 	while (files->next)
// 	{
// 		next = files->next;
// 		if (last_ocurrence(files->value, temp) == TRUE)
// 			files = files->next;
// 		else
// 		{
// 			free(files->value);
// 			free(files);
// 			files = next;
// 		}
// 	}
// 	free(temp);
// 	print_token(files);
// 	return (NULL);
// }

// t_bool	is_init_wildcard(char *wildcard)
// {
// 	if (wildcard[0] == '*')
// 		return (FALSE);
// 	return (TRUE);
// }

// t_token	*analize_wildcard(t_token *files, char *wildcard)
// {
// 	if (is_init_wildcard(wildcard) == FALSE)
// 		initial_wildcard(wildcard, files);
// 	return (NULL);
// }

// void	expand_wildcard(void)
// {
// 	t_token	*tkn;
// 	t_token	*next_token;
// 	t_token	*tmp;

// 	tkn = find_wild();
// 	if (!tkn)
// 		return ;
// 	next_token = tkn->next;
// 	tkn->next = NULL;
// 	tmp = list_files();
// 	analize_wildcard(tmp, tkn->value);
// }
