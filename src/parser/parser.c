/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:19:45 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/07 18:44:54 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_var_exit(void)
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
				tmp->content[i] = '\0';
				tmp->content = ft_strjoin(tmp->content, exit_status);
				tmp->content = ft_strjoin(tmp->content, tmp->content + i + 2);
				free(exit_status);
			}
		}
		tmp = tmp->next;
	}
}
