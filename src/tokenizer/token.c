/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:26:04 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/30 14:23:53 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_list(void *list)
{
	t_token	token_list;

	token_list = *(t_token *)list;
	printf("%s\n", token_list.value);
	printf("%d\n", token_list.type);
}

void	tokenization(t_minishell *core)
{
	t_token	token;
	int		i;

	i = 0;
	while (core->splited_input)
	{
		if (!ft_isprint(*(char *)(core->splited_input)->content))
		{
			core->splited_input = (core->splited_input)->next;
			continue ;
		}
		token.value = (char *)(core->splited_input)->content;
		if (core->splited_input->next && !ft_strcmp(token.value,
				(char *)(core->splited_input->next)->content))
		{
			token.value = ft_strjoin(token.value,
				(char *)(core->splited_input->next)->content);
			core->splited_input = (core->splited_input)->next;
		}
		token.type = set_token_type(token.value);
		ft_lstadd_back(&core->token_list, ft_lstnew(&token));
		core->splited_input = (core->splited_input)->next;
		ft_print_list(core->token_list->content);
	}
}
