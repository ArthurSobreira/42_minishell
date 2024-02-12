/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:26:04 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/12 11:21:25 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_tkn_type	set_tkn_type(char *str)
// {
// 	if (!ft_strcmp(str, "||"))
// 		return (TOKEN_OR);
// 	if (!ft_strcmp(str, "&&"))
// 		return (TOKEN_AND);
// 	if (!ft_strcmp(str, ">>"))
// 		return (TOKEN_APPEND);
// 	if (!ft_strcmp(str, ">"))
// 		return (TOKEN_REDIRECT);
// 	if (!ft_strcmp(str, "<"))
// 		return (TOKEN_REDIRECT_REVERSE);
// 	if (!ft_strcmp(str, "|"))
// 		return (TOKEN_PIPE);
// 	if (!ft_strcmp(str, "&"))
// 		return (TOKEN_BACKGROUND);
// 	if (!ft_strcmp(str, "<<"))
// 		return (TOKEN_HERE_DOC);
// 	if (!ft_strcmp(str, ";"))
// 		return (TOKEN_SEMICOLON);
// 	if (str[0] == '\"')
// 		return (TOKEN_DQUOTE);
// 	if (str[0] == '\'')
// 		return (TOKEN_SQUOTE);
// 	return (TOKEN_WORD);
// }

// t_token	*new_token(char *str)
// {
// 	t_token	*token;

// 	token = (t_token *)malloc(sizeof(t_token));
// 	token->value = ft_strdup(str);
// 	token->type = set_tkn_type(str);
// 	token->next = NULL;
// 	token->prev = NULL;
// 	return (token);
// }

// void	add_token(t_token **head, t_token *new)
// {
// 	t_token	*tmp;

// 	if (!*head)
// 	{
// 		*head = new;
// 		return ;
// 	}
// 	tmp = *head;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	tmp->next = new;
// 	new->prev = tmp;
// }

// void	tokenization(void)
// {
// 	t_input	*tmp;
// 	t_token	*token;
// 	char	*str;
// 	char	dup;

// 	split_input();
// 	if (!get_core()->error_msg)
// 		return ;
// 	tmp = get_core()->splited_input;
// 	while (tmp)
// 	{
// 		str = ft_strdup(tmp->content);
// 		if (tmp->next && !ft_strcmp(tmp->next->content, str))
// 		{
// 			dup = str[0];
// 			ft_free(str);
// 			str = ft_strduplicate_char(dup);
// 			tmp = tmp->next;
// 		}
// 		token = new_token(str);
// 		add_token(&get_core()->token_list, token);
// 		tmp = tmp->next;
// 		ft_free(str);
// 	}
// 	look_for_variables();
// }
