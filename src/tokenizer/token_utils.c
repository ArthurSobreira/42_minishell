/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:35:51 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/08 14:14:56 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_input	*new_node(char *str)
{
	t_input	*new;

	new = malloc(sizeof(t_input));
	if (!new)
		return (NULL);
	new->content = str;
	new->next = NULL;
	return (new);
}

void	split_input(void)
{
	t_minishell	*core_tmp;
	int			i;
	char		quote;
	int			start;

	i = -1;
	core_tmp = get_core();
	ft_strip(core_tmp->input);
	while (core_tmp->input[++i])
	{
		if (core_tmp->input[i] == '\'' || core_tmp->input[i] == '\"')
		{
			quote = core_tmp->input[i];
			start = i;
			while (core_tmp->input[++i] != quote && core_tmp->input[i] != '\0')
				;
			if (core_tmp->input[i] == '\0')
				ft_error("syntax error: unexpected end of file\n", 2);
			add_to_list(core_tmp, start, i + 1);
		}
		else if (core_tmp->input[i] != ' ')
			process_non_space(core_tmp, &i);
	}
}

void	process_non_space(t_minishell *core, int *i)
{
	int		start;
	char	quote;

	start = *i;
	while (isall(core, i))
	{
		if (core->input[*i] == '\'' || core->input[*i] == '\"')
		{
			quote = core->input[*i];
			while (core->input[++(*i)] != quote && core->input[*i] != '\0')
				;
		}
		else
			(*i)++;
	}
	add_to_list(core, start, *i);
	while (ft_ispipe(core->input[*i]) || ft_issemicolon(core->input[*i])
		|| ft_isredir(core->input[*i]) || ft_isbackground(core->input[*i]))
	{
		add_to_list(core, *i, *i + 1);
		(*i)++;
	}
	(*i)--;
}

void	add_to_list(t_minishell *core, int start, int end)
{
	char	*str;
	t_input	*tmp;
	t_input	*new;

	str = ft_substr(core->input, start, end - start);
	if (!ft_isprint(str[0]))
	{
		ft_free(str);
		return ;
	}
	new = new_node(str);
	if (!core->splited_input)
	{
		core->splited_input = new;
		return ;
	}
	tmp = core->splited_input;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_bool	is_redir_token(t_token *token)
{
	if (token->type == TOKEN_REDIRECT ||
		token->type == TOKEN_APPEND ||
		token->type == TOKEN_REDIRECT_REVERSE ||
		token->type == TOKEN_HERE_DOC)
		return (TRUE);
	return (FALSE);
}

t_bool	isall(t_minishell *core, int *i)
{
	return (!ft_isspace(core->input[*i]) && !ft_ispipe(core->input[*i])
		&& !ft_issemicolon((core->input[*i])) && !ft_isredir(core->input[*i])
		&& !ft_isbackground(core->input[*i]) && core->input[*i] != '\"'
		&& core->input[*i] != '\'' && core->input[*i] != '\0');
}
