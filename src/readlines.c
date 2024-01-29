/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:18:27 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/29 19:31:45 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	readlines(t_minishell *core)
{
	char	*prompt;

	using_history();
	while (TRUE)
	{
		prompt = get_prompt_text(core);
		core->input = readline(prompt);
		free(prompt);
		add_history(core->input);
		ft_strip(core->input);
		printf("input: %s\n", core->input);
		split_quote(core);
		// tokenization(core);
		if (core->input[0] == '\0')
			continue ;
		if (ft_strcmp(core->input, "exit") == 0)
			exit_shell();
		if (ft_strcmp(core->input, "pwd") == 0)
			print_working_directory();
	}
}
