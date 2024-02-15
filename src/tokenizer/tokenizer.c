/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:15:36 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/13 15:16:30 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_tkn_type	set_tkn_type(char *str)
{
	if (!ft_strcmp(str, ">>"))
		return (TOKEN_APPEND);
	if (!ft_strcmp(str, ">"))
		return (TOKEN_REDIRECT);
	if (!ft_strcmp(str, "<"))
		return (TOKEN_REDIRECT_REVERSE);
	if (!ft_strcmp(str, "|"))
		return (TOKEN_PIPE);
	if (!ft_strcmp(str, "<<"))
		return (TOKEN_HERE_DOC);
	return (TOKEN_WORD);
}

t_token	*new_token(char *str)
{
	t_token	*token;
	char	*tmp;

	tmp = ft_strdup(str);
	ft_strip(tmp);
	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = tmp;
	token->type = set_tkn_type(str);
	token->next = NULL;
	token->prev = NULL;
	free(str);
	return (token);
}

t_bool	is_redir_token(t_token *token)
{
	if (token->type == TOKEN_REDIRECT || \
	token->type == TOKEN_APPEND || \
	token->type == TOKEN_REDIRECT_REVERSE || \
	token->type == TOKEN_HERE_DOC)
		return (TRUE);
	return (FALSE);
}

void	splited_add_back(t_token **head, t_token *new)
{
	t_token	*tmp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	split_input(char *str)
{
	t_token	*splited;
	char	*token;
	char	*tmp;

	tmp = "\n";
	splited = NULL;
	token = ft_strtok(str, tmp);
	while (token)
	{
		splited_add_back(&splited, new_token(token));
		token = ft_strtok(NULL, tmp);
	}
	get_core()->token_list = splited;
	ft_printf("---------------\n");
	print_token(get_core()->token_list);
}