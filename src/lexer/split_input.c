/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:14:00 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/08 10:20:00 by phenriq2         ###   ########.fr       */
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

char	*replace(char *str, char *tmp, char *tmp2)
{
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
	str = check_empty_quotes(str);
	return (str);
}

char	*insert_spaces(char *str)
{
	char	*tmp;
	char	*tmp2;
	char	c;
	char	d;

	c = -1;
	d = -2;
	tmp = ft_strnew(1);
	tmp2 = ft_strnew(1);
	tmp[0] = c;
	tmp2[0] = d;
	str = replace(str, tmp, tmp2);
	free(tmp);
	free(tmp2);
	return (str);
}

char	*check_empty_quotes(char *str)
{
	if (((str[0] == '\'' && str[1] == '\'') ||
			(str[0] == '\"' && str[1] == '\"')) &&
		((ft_isspace(str[2])) || (str[2] == '\0')))
	{
		str = ft_replace_dquotes(str, "\'\'", "' '");
		str = ft_replace_quotes(str, "\"\"", "\" \"");
	}
	return (str);
}

t_bool	lexer_and_format_prompt(void)
{
	char	*str_error;
	char	*str;

	if (get_core()->input[0] == '\0')
		return (FALSE);
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
	// expand_wildcard();
	check_variables();
	return (FALSE);
}
