/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:09:31 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/12 17:35:57 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt_loop(void)
{
	char	*prompt;
	char	*error_msg;

	using_history();
	while (TRUE)
	{
		prompt = get_prompt_text();
		get_core()->input = readline(prompt);
		add_history(get_core()->input);
		if (get_core()->input[0] == '\0')
			continue ;
		ft_strip(get_core()->input);
		error_msg = parser_and_split();
		if (error_msg)
		{
			set_exit_status(error_msg);
			continue ;
		}
		garbage_add(get_core()->input);
		if (ft_strcmp(get_core()->input, "exit") == 0)
			exit_shell();
		if (ft_strcmp(get_core()->input, "pwd") == 0)
			print_working_directory();
		if (ft_strcmp(get_core()->input, "env") == 0)
			print_env_variables();
		clear_garbage();
	}
	rl_clear_history();
}
// core->error_msg = TRUE;
// handle_redirects();
// tokenization();
// parser();

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
	garbage_add(prompt_data.prompt);
	return (prompt_data.prompt);
}
