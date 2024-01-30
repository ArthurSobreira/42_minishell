/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:35:51 by arsobrei          #+#    #+#             */
/*   Updated: 2024/01/30 14:46:57 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list_ms	*new_node(char *str)
{
	t_list_ms	*new;

	new = malloc(sizeof(t_list_ms));
	if (!new)
		return (NULL);
	new->content = str;
	new->next = NULL;
	return (new);
}

t_token_type	set_token_type(char *str)
{
	if (!ft_strcmp(str, "||"))
		return (TOKEN_OR);
	if (!ft_strcmp(str, "&&"))
		return (TOKEN_AND);
	if (!ft_strcmp(str, ">>"))
		return (TOKEN_APPEND);
	if (!ft_strcmp(str, ">"))
		return (TOKEN_REDIRECT);
	if (!ft_strcmp(str, "<"))
		return (TOKEN_REDIRECT_REVERSE);
	if (!ft_strcmp(str, "|"))
		return (TOKEN_PIPE);
	if (!ft_strcmp(str, "&"))
		return (TOKEN_BACKGROUND);
	if (!ft_strcmp(str, "<<"))
		return (TOKEN_HERE_DOC);
	if (str[0] == '\"')
		return (TOKEN_QUOTE);
	return (TOKEN_WORD);
}

void	split_input(t_minishell *core)
{
	int		i;
	char	quote;
	int		start;

	i = -1;
	ft_strip(core->input);
	while (core->input[++i])
	{
		if (core->input[i] == '\'' || core->input[i] == '\"')
		{
			quote = core->input[i];
			start = i;
			while (core->input[++i] != quote && core->input[i] != '\0')
				;
			add_to_list(core, start, i + 1);
		}
		else if (core->input[i] != ' ')
			process_non_space(core, &i);
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

static void	add_to_list(t_minishell *core, int start, int end)
{
	char		*str;
	t_list_ms	*tmp;
	t_list_ms	*new;

	str = ft_substr(core->input, start, end - start);
	if (ft_isprint(str[0]) == 0)
		return ;
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

t_bool	isall(t_minishell *core, int *i)
{
	return (!ft_isspace(core->input[*i]) && !ft_ispipe(core->input[*i])
		&& !ft_issemicolon((core->input[*i])) && !ft_isredir(core->input[*i])
		&& !ft_isbackground(core->input[*i]) && core->input[*i] != '\0');
}
