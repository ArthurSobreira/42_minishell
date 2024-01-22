/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:15:36 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/22 18:38:52 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_list(t_list *list)
{
	while (list)
	{
		printf("list: %s\n", list->content);
		list = list->next;
	}
}

void	split_quote(t_minishell *core)
{
	int		i;
	int		start;
	char	quote;

	i = -1;
	while (core->input[++i])
	{
		if (core->input[i] == '\'' || core->input[i] == '\"')
		{
			quote = core->input[i];
			start = i;
			while (core->input[++i] != quote && core->input[i] != '\0')
				;
			ft_lstadd_back(&core->splited_input,
				ft_lstnew(ft_substr(core->input, start, i - start + 1)));
		}
		else if (core->input[i] != ' ')
		{
			start = i;
			while (core->input[++i] != ' ' && core->input[i] != '\0')
				;
			ft_lstadd_back(&core->splited_input,
				ft_lstnew(ft_substr(core->input, start, i - start)));
		}
	}
	ft_print_list(core->splited_input);
}
