/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:34:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/29 16:50:58 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_strip(char *str)
{
	size_t	len;
	size_t	start;
	size_t	end;

	if (str == NULL || *str == '\0')
		return ;
	len = ft_strlen(str);
	start = 0;
	end = len - 1;
	while (start < len && (str[start] == ' ' || str[start] == '\t'
			|| str[start] == '\n' || str[start] == '\v' || str[start] == '\f'
			|| str[start] == '\r'))
		start++;
	while (end > start && (str[end] == ' ' || str[end] == '\t'
			|| str[end] == '\n' || str[end] == '\v' || str[end] == '\f'
			|| str[end] == '\r'))
		end--;
	ft_memmove(str, str + start, end - start + 1);
	str[end - start + 1] = '\0';
}

void	free_token_list(t_list *token_list)
{
	t_list	*temp;
	t_token	*token;

	while (token_list)
	{
		temp = token_list;
		token = (t_token *)temp->content;
		free(token->value);
		token_list = token_list->next;
		free(temp);
	}
}

void	ft_error(char *str, int status)
{
	t_minishell	*core;

	core = get_core();
	ft_putstr_fd(str, STDERR_FILENO);
	if (core->input != NULL)
		free(core->input);
	if (core->token_list)
		free_token_list(core->token_list);
	rl_clear_history();
	exit(status);
}
