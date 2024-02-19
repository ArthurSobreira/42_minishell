/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:33:37 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/13 19:35:07 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	capture_heredoc(t_token *current_tkn)
{
	t_token		*current_cpy;
	char		*hd_limiter;
	int			here_doc_fd;

	current_cpy = current_tkn;
	while (current_cpy)
	{
		if ((current_cpy->type == TOKEN_HERE_DOC) && \
			(current_cpy->next->type == TOKEN_WORD))
		{
			here_doc_fd = open(HERE_DOC_FILE, \
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
			hd_limiter = current_cpy->next->value;
			here_doc_loop(hd_limiter, here_doc_fd);
		}
		current_cpy = current_cpy->next;
	}
}

char	*search_for_expansions(t_var *env_vars, char *line)
{
	char	expanded_line[MAX_VAR_LEN];
	char	*result_line;
	t_var	*temp_var;
	size_t	line_index;
	size_t	e_line_index;

	if (!ft_strchr(line, '$'))
		return (line);
	temp_var = env_vars;
	line_index = 0;
	e_line_index = 0;
	while (line[line_index])
	{
		if (line[line_index] == '$')
		{
			line_index++;
			while (ft_isalnum(line[line_index]))
				expanded_line[e_line_index++] = line[line_index++];
			expanded_line[e_line_index] = '\0';
			while (temp_var)
			{
				if (!ft_strcmp(expanded_line, temp_var->key))
				{
					ft_strlcat(expanded_line, temp_var->value, MAX_VAR_LEN);
					break ;
				}
				temp_var = temp_var->next;
			}
		}
		else
			expanded_line[e_line_index++] = line[line_index++];
	}
	expanded_line[e_line_index] = '\0';
	line_index = 0;
	while (expanded_line[line_index])
		line_index++;
	result_line = (char *)malloc(sizeof(char) * (line_index + 1));
	if (!result_line)
		return (NULL);
	ft_strlcpy(result_line, expanded_line, line_index + 1);
	free(line);
	return (result_line);
}

void	here_doc_loop(char *hd_limiter, int here_doc_fd)
{
	char	*line;

	while (TRUE)
	{
		line = readline("> ");
		if (!ft_strcmp(line, hd_limiter))
		{
			free(line);
			close(here_doc_fd);
			break ;
		}
		search_for_expansions(get_core()->env_vars, line);
		ft_putendl_fd(line, here_doc_fd);
		free(line);
	}
}
