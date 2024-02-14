/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:14:00 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/14 10:03:11 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_first_errors(void)
{
	if (check_close_quotes() == FALSE)
		return ("syntax error: unexpected end of file");
	if (check_forbidden_or() == FALSE)
		return ("syntax error: unexpected token `||'");
	if (check_forbidden_and() == FALSE)
		return ("syntax error: unexpected token `&&'");
	if (check_forbidden_semicolon() == FALSE)
		return ("syntax error: unexpected token `;'");
	if (check_forbidden_background() == FALSE)
		return ("syntax error: unexpected token `&'");
	if (check_start_pipe() == FALSE)
		return ("syntax error: unexpected token `|'");
	if (check_end_operators() == FALSE)
		return ("syntax error: unexpected end of file");
	return (NULL);
}

char	*insert_spaces(char *str)
{
	char	*tmp;
	char	*tmp2;

	tmp = "\n";
	tmp2 = "\a";
	str = ft_replace(str, ">>", tmp);
	str = ft_replace(str, ">", tmp2);
	str = ft_replace(str, tmp2, " > ");
	str = ft_replace(str, tmp, " >> ");
	str = ft_replace(str, "<<", tmp);
	str = ft_replace(str, "<", tmp2);
	str = ft_replace(str, tmp2, " < ");
	str = ft_replace(str, tmp, " << ");
	str = ft_replace(str, "|", tmp);
	str = ft_replace(str, tmp, " | ");
	str = ft_replace(str, " ", tmp);
	return (str);
}

t_bool	lexer_and_format_prompt(void)
{
	char	*str_error;
	char	*str;

	str_error = check_first_errors();
	if (str_error)
	{
		set_exit_status(str_error);
		return (TRUE);
	}
	str = ft_strdup(get_core()->input);
	str = insert_spaces(str);
	garbage_add(str);
	split_input(str);
	check_variables();
	return (FALSE);
}
// return (NULL);
