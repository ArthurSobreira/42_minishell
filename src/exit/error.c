/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:34:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/31 18:08:29 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear_token(void)
{
	t_minishell	*core;
	t_token		*tmp;

	core = get_core();
	if (core->token_list == NULL)
		return ;
	while (core->token_list)
	{
		tmp = core->token_list->next;
		if (core->token_list->type == TOKEN_APPEND
			|| core->token_list->type == TOKEN_HERE_DOC
			|| core->token_list->type == TOKEN_OR
			|| core->token_list->type == TOKEN_AND)
			ft_free(core->token_list->value);
		ft_free(core->token_list);
		core->token_list = tmp;
	}
}

void	ft_clear_splited_input(void)
{
	t_minishell	*core;
	t_input	*tmp;
	t_input	*tmp;

	core = get_core();
	if (core->splited_input == NULL)
		return ;
	while (core->splited_input)
	{
		tmp = core->splited_input->next;
		free(core->splited_input->content);
		free(core->splited_input);
		core->splited_input = tmp;
	}
	ft_clear_token();
}

void	ft_error(char *str, int status)
{
	t_minishell	*core;

	core = get_core();
	ft_putstr_fd(str, STDERR_FILENO);
	if (core->input != NULL)
		free(core->input);
	if (core->splited_input != NULL)
		ft_clear_splited_input();
	exit(status);
}
