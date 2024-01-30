/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:34:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/30 15:20:44 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear_splited_input(void)
{
	t_minishell	*core;
	t_list_ms	*tmp;

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
}

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
		free(core->token_list->value);
		free(core->token_list);
		core->token_list = tmp;
	}
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
	if (core->token_list != NULL)
		ft_clear_token();
	exit(status);
}
