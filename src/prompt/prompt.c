/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:09:31 by arsobrei          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/06 19:38:17 by phenriq2         ###   ########.fr       */
=======
/*   Updated: 2024/02/06 15:21:19 by arsobrei         ###   ########.fr       */
>>>>>>> f1f373ee6d21f4978e9f701e95d8b0e6a99dc008
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt_loop(t_minishell *core)
{
	char	*prompt;

	using_history();
	while (TRUE)
	{
		prompt = get_prompt_text();
		core->input = readline(prompt);
		free(prompt);
		add_history(core->input);
		tokenization();
		handle_redirects();
		if (core->input[0] == '\0')
			continue ;
		if (ft_strcmp(core->input, "exit") == 0)
			exit_shell();
		if (ft_strcmp(core->input, "pwd") == 0)
			print_working_directory();
		if (ft_strcmp(core->input, "env") == 0)
			print_env_variables();
		free(core->input);
		ft_clear_splited_input();
	}
	rl_clear_history();
}

char	*get_prompt_text(void)
{
	t_prompt	prompt_data;

	prompt_data = init_prompt();
	prompt_data.user = get_username();
	prompt_data.hostname = format_hostname(get_hostname());
	prompt_data.current_dir = get_current_dir();
	prompt_data.prompt = format_prompt(&prompt_data);
	free(prompt_data.user);
	free(prompt_data.hostname);
	free(prompt_data.current_dir);
	return (prompt_data.prompt);
}
