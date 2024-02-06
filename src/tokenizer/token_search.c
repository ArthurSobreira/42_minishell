/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:01:04 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/06 19:23:45 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_occurrences(char *str, int c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

t_bool	is_excluded_type(t_tkn_type type, int option)
{
	if (option == 1 && (type == TOKEN_AND || type == TOKEN_OR
			|| type == TOKEN_SEMICOLON || type == TOKEN_BACKGROUND))
		return (TRUE);
	else if (option == 2 && (type == TOKEN_PIPE || type == TOKEN_REDIRECT
				|| type == TOKEN_REDIRECT_REVERSE || type == TOKEN_APPEND
				|| type == TOKEN_HERE_DOC || type == TOKEN_AND
				|| type == TOKEN_OR || type == TOKEN_SEMICOLON
				|| type == TOKEN_BACKGROUND))
		return (TRUE);
	return (FALSE);
}

void	pipe_and_operator_error(void)
{
	t_minishell	*core;
	t_token		*tmp;

	core = get_core();
	tmp = core->token_list;
	while (tmp->next)
	{
		if ((tmp->type == TOKEN_PIPE && tmp->next->type != TOKEN_WORD)
			|| (tmp->type == TOKEN_APPEND && tmp->next->type != TOKEN_WORD)
			|| (tmp->type == TOKEN_REDIRECT && tmp->next->type != TOKEN_WORD)
			|| (tmp->type == TOKEN_REDIRECT_REVERSE
				&& tmp->next->type != TOKEN_WORD))
			ft_error("syntax error: unexpected token\n", 2);
		tmp = tmp->next;
	}
}

void	search_bugs(void)
{
	t_token	*tmp;

	tmp = get_core()->token_list;
	if (get_core()->token_list->type == TOKEN_PIPE)
		ft_error("syntax error: unexpected token\n", 2);
	while (tmp->next)
	{
		if (is_excluded_type(tmp->type, 1))
			ft_error("syntax error: command not found\n", 127);
		tmp = tmp->next;
	}
	if (is_excluded_type(tmp->type, 2))
		ft_error("syntax error: unexpected end of file\n", 2);
	pipe_and_operator_error();
	tmp = get_core()->token_list;
	print_token(tmp);
}
