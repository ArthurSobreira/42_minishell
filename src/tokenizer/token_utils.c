/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:35:51 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/12 11:21:02 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_input	*new_node(char *str)
// {
// 	t_input	*new;

// 	new = malloc(sizeof(t_input));
// 	if (!new)
// 		return (NULL);
// 	new->content = str;
// 	new->next = NULL;
// 	return (new);
// }

// void	split_input(void)
// {
// 	int		i;
// 	char	quote;
// 	int		start;

// 	i = -1;
// 	ft_strip(get_core()->input);
// 	while (get_core()->input[++i])
// 	{
// 		if (get_core()->input[i] == '\'' || get_core()->input[i] == '\"')
// 		{
// 			quote = get_core()->input[i];
// 			start = i;
// 			while (get_core()->input[++i] != quote
// 				&& get_core()->input[i] != '\0')
// 				;
// 			if (get_core()->input[i] == '\0')
// 			{
// 				ft_error("syntax error: unexpected end of file\n", 2);
// 				return ;
// 			}
// 			add_to_list(get_core(), start, i + 1);
// 		}
// 		else if (get_core()->input[i] != ' ')
// 			process_non_space(get_core(), &i);
// 	}
// }

// void	process_non_space(t_minishell *core, int *i)
// {
// 	int		start;
// 	char	quote;

// 	start = *i;
// 	while (isall(core, i))
// 	{
// 		if (core->input[*i] == '\'' || core->input[*i] == '\"')
// 		{
// 			quote = core->input[*i];
// 			while (core->input[++(*i)] != quote && core->input[*i] != '\0')
// 				;
// 		}
// 		else
// 			(*i)++;
// 	}
// 	add_to_list(core, start, *i);
// 	while (ft_ispipe(core->input[*i]) || ft_issemicolon(core->input[*i])
// 		|| ft_isredir(core->input[*i]) || ft_isbackground(core->input[*i]))
// 	{
// 		add_to_list(core, *i, *i + 1);
// 		(*i)++;
// 	}
// 	(*i)--;
// }

// void	add_to_list(t_minishell *core, int start, int end)
// {
// 	char	*str;
// 	t_input	*tmp;
// 	t_input	*new;

// 	str = ft_substr(core->input, start, end - start);
// 	if (!ft_isprint(str[0]))
// 	{
// 		ft_free(str);
// 		return ;
// 	}
// 	new = new_node(str);
// 	if (!core->splited_input)
// 	{
// 		core->splited_input = new;
// 		return ;
// 	}
// 	tmp = core->splited_input;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	tmp->next = new;
// }

// t_bool	is_redir_token(t_token *token)
// {
// 	if (token->type == TOKEN_REDIRECT ||
// 		token->type == TOKEN_APPEND ||
// 		token->type == TOKEN_REDIRECT_REVERSE ||
// 		token->type == TOKEN_HERE_DOC)
// 		return (TRUE);
// 	return (FALSE);
// }

// t_bool	isall(t_minishell *core, int *i)
// {
// 	return (!ft_isspace(core->input[*i]) && !ft_ispipe(core->input[*i])
// 		&& !ft_issemicolon((core->input[*i])) && !ft_isredir(core->input[*i])
// 		&& !ft_isbackground(core->input[*i]) && core->input[*i] != '\"'
// 		&& core->input[*i] != '\'' && core->input[*i] != '\0');
// }
