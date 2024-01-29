/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:15:36 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/29 16:18:04 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_to_list(t_minishell *core, int start, int end)
{
	char	*str;

	str = ft_substr(core->input, start, end - start);
	ft_lstadd_back(&core->splited_input, ft_lstnew(str));
}

static t_bool	isall(t_minishell *core, int *i)
{
	return (!isspace(core->input[*i]) && !ispipe(core->input[*i])
		&& !issemicolon((core->input[*i])) && !isredir(core->input[*i])
		&& !isbackground(core->input[*i]) && core->input[*i] != '\0');
}

static void	process_non_space(t_minishell *core, int *i)
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
	while (ispipe(core->input[*i]) || issemicolon(core->input[*i])
		|| isredir(core->input[*i]) || isbackground(core->input[*i]))
	{
		add_to_list(core, *i, *i + 1);
		(*i)++;
	}
	(*i)--;
}

void	split_quote(t_minishell *core)
{
	int		i;
	char	quote;
	int		start;

	i = -1;
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
