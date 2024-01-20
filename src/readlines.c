/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:18:27 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/20 17:06:09 by phenriq2         ###   ########.fr       */
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
		input_analysis(core);
		execute_builtin(core);
	}
	rl_clear_history();
}
