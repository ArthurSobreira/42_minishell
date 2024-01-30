/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:09:31 by arsobrei          #+#    #+#             */
/*   Updated: 2024/01/29 19:05:47 by arsobrei         ###   ########.fr       */
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
		ft_strip(core->input);
		printf("input: %s\n", core->input);
		split_quote(core);
		tokenization(core);
		if (core->input[0] == '\0')
			continue ;
		if (ft_strcmp(core->input, "exit") == 0)
			exit_shell();
		if (ft_strcmp(core->input, "pwd") == 0)
			print_working_directory();
		free(core->input);
		if (core->splited_input)
			ft_lstclear(&core->splited_input, free);
	}
	rl_clear_history();
}

char	*get_prompt_text(t_minishell *core)
{
	t_prompt	*prompt_data;

	prompt_data = init_prompt();
	prompt_data->user = get_username();
	prompt_data->hostname = format_hostname(get_hostname(core));
	prompt_data->current_dir = get_current_dir();
	prompt_data->prompt = format_prompt(prompt_data);
	free(prompt_data->user);
	free(prompt_data->hostname);
	free(prompt_data->current_dir);
	return (prompt_data->prompt);
}
