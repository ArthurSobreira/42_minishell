/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:18:27 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/20 19:23:14 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	readlines(t_minishell *core)
{
	char	*prompt;

	using_history();
	while (1)
	{
		prompt = ft_strjoin(getenv("USER"), "@minishell: ");
		prompt = ft_strjoin(ft_strjoin(COLOR_PINK, prompt), COLOR_RESET);
		core->input = readline(prompt);
		free(prompt);
		add_history(core->input);
		ft_strip(core->input);
		ft_printf("input: %s\n", core->input);
		splite_input(core);
		ft_lstclear(&core->splited_input, free);
	}
	rl_clear_history();
}

		// execute_builtin(core);
		// get_first_cmd(core);