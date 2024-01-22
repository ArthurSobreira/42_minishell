/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:18:27 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/22 12:57:09 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	readlines(t_minishell *core)
{
	char	*prompt;

	using_history();
	while (TRUE)
	{
		prompt = ft_strjoin(getenv("USER"), "@minishell: ");
		prompt = ft_strjoin(ft_strjoin(COLOR_PINK, prompt), COLOR_RESET);
		core->input = readline(prompt);
		free(prompt);
		add_history(core->input);
		ft_strip(core->input);
		splite_input(core);
		ft_lstclear(&core->splited_input, free);
	}
	rl_clear_history();
}