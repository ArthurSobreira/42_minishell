/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:26:04 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/29 16:49:46 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_token(t_token *token)
{
	printf("value: %s\n", token->value);
	printf("type: %d\n", token->type);
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

void	tokenization(t_minishell *core)
{
	t_token	token;
	int		i;

	i = 0;
	while (core->splited_input)
	{
		if (!ft_isprint(*(char *)(core->splited_input)->content))
		{
			free((char *)(core->splited_input)->content);
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
		print_token((t_token *)(core->token_list->content));
	}
}
