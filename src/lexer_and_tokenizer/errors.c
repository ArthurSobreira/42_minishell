/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:09:05 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/26 12:43:38 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	export_error(void)
{
	t_token	*tmp;

	tmp = get_core()->token_list;
	while (tmp)
	{
		if (tmp->prev && !ft_strcmp(tmp->prev->value, "export")
			&& tmp->type == TOKEN_WORD && (!ft_isalpha(tmp->value[0])
				&& tmp->value[0] != '_'))
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

t_bool	operators_after_operators(void)
{
	t_token	*tmp;

	tmp = get_core()->token_list;
	while (tmp)
	{
		if (tmp->type == TOKEN_APPEND || tmp->type == TOKEN_HERE_DOC
			|| tmp->type == TOKEN_REDIRECT
			|| tmp->type == TOKEN_REDIRECT_REVERSE)
		{
			if (tmp->next && tmp->next->type != TOKEN_WORD)
				return (TRUE);
		}
		tmp = tmp->next;
	}
	return (FALSE);
}

char	*check_parser_errors(void)
{
	if (operators_after_operators())
		return ("syntax error: unexpected token after operator");
	if (export_error())
		return (EXPORT_ERROR);
	return (NULL);
}

t_bool	parser(void)
{
	char	*str_error;

	str_error = check_parser_errors();
	if (str_error)
	{
		set_exit_status(str_error);
		return (TRUE);
	}
	return (FALSE);
}
