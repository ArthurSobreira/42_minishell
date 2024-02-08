/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:19:45 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/08 19:16:53 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_last_status(void)
{
	t_minishell	*core;
	t_input		*tmp;
	int			i;
	char		*exit_status;

	core = get_core();
	tmp = core->splited_input;
	while (tmp)
	{
		i = -1;
		while (tmp->content[++i])
		{
			if (tmp->content[i] == '$' && tmp->content[i + 1] == '?')
			{
				free(tmp->content);
				exit_status = ft_itoa(core->exit_status);
				tmp->content = ft_strdup(exit_status);
				perror("exit_status");
				free(exit_status);
			}
		}
		tmp = tmp->next;
	}
}

void	parser(void)
{
	printf("debug %d\n", get_core()->error_msg);
	if (!get_core()->error_msg)
		return ;
	// if (!search_bugs())
	// 	return ;
	if (!pipe_and_operator_error())
		return ;
	check_last_status();
}
