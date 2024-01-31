/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:09:31 by arsobrei          #+#    #+#             */
/*   Updated: 2024/01/31 18:50:58 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt_loop(t_minishell *core)
{
	char	*prompt;

	using_history();
	while (TRUE)
	{
		prompt = get_prompt_text(core);
		core->input = readline(prompt);
		free(prompt);
		add_history(core->input);
		printf("input: %s\n", core->input);
		tokenization(core);
		if (core->input[0] == '\0')
			continue ;
		if (ft_strcmp(core->input, "exit") == 0)
			exit_shell();
		if (ft_strcmp(core->input, "pwd") == 0)
			print_working_directory();
		free(core->input);
		ft_clear_splited_input();
	}
	rl_clear_history();
}

char	*get_prompt_text(t_minishell *core)
{
	t_prompt	prompt_data;

	prompt_data = init_prompt();
	prompt_data.user = get_username();
	prompt_data.hostname = format_hostname(get_hostname(core));
	prompt_data.current_dir = get_current_dir();
	prompt_data.prompt = format_prompt(&prompt_data);
	free(prompt_data.user);
	free(prompt_data.hostname);
	free(prompt_data.current_dir);
	return (prompt_data.prompt);
}
