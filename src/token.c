/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:26:04 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/29 19:29:07 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void print_token_list(t_token *token_list)
{
	while (token_list)
	{
		printf("token:\n");
		printf("value: %s\n", token_list->value);
		printf("type: %d\n", token_list->type);
		token_list = token_list->next;
	}
}

void	add_to_node(t_token *node, t_token token)
{
	t_token	*new;

	new = new_token(token);
	while (node->next)
		node = node->next;
	node->next = new;
}

t_token	*new_token(t_token token)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->value = token.value;
	new->type = token.type;
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

void	tokenization(t_minishell *core)
{
	t_token	token;
	
	while(core->splited_input)
	{
		if(!ft_isprint(core->splited_input->content[0]))
		{
			core->splited_input = core->splited_input->next;
			continue ;
		}
		token.value = core->splited_input->content;
		token.type = set_token_type(token.value);
		if (!core->token_list)
			core->token_list = new_token(token);
		else
			add_to_node(core->token_list, token);
		core->splited_input = core->splited_input->next;
	}
	print_token_list(core->token_list);
}
