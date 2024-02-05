/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:26:04 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/05 19:02:01 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		printf("type: %d\n", tmp->type);
		printf("value: %s\n", tmp->value);
		tmp = tmp->next;
	}
}

t_tkn_type	set_tkn_type(char *str)
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
	if (!ft_strcmp(str, ";"))
		return (TOKEN_SEMICOLON);
	if (str[0] == '\"')
		return (TOKEN_QUOTE);
	return (TOKEN_WORD);
}

t_token	*new_token(char *str)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->type = set_tkn_type(str);
	token->value = str;
	token->next = NULL;
	token->prev = NULL;
	return (token);
}

void	add_token(t_token **head, t_token *new)
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

void	search_bad_redirects(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '>' || str[i] == '<')
		{
			while (str[++i] == ' ')
			{
				i++;
				if (str[i] == '<' || str[i] == '>')
					ft_error("syntax error: unexpected token\n", 2);
			}
		}
	}
}

void	tokenization(void)
{
	t_input	*tmp;
	t_token	*token;
	char	*str;
	char	*temp_str;

	split_input();
	search_bad_redirects(get_core()->input);
	tmp = get_core()->splited_input;
	temp_str = NULL;
	while (tmp)
	{
		str = tmp->content;
		if (tmp->next && !ft_strcmp(tmp->next->content, str))
		{
			temp_str = str;
			str = ft_strjoin(temp_str, str);
			tmp = tmp->next;
		}
		token = new_token(str);
		add_token(&get_core()->token_list, token);
		tmp = tmp->next;
	}
	print_token(get_core()->token_list);
	search_bugs();
}
