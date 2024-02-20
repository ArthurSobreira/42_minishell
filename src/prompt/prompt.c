/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:09:31 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/20 11:55:52 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	parser(void)
{
	return (FALSE);
}

t_bool	execution(void)
{
	return (FALSE);
}

void	prompt_process(t_minishell *core)
{
	if (lexer_and_format_prompt())
		return ;
	if (parser())
		return ;
	capture_heredoc();
	command_executor();
	if (ft_strcmp(core->input, "exit") == 0)
		exit_shell();
	if (ft_strcmp(core->input, "pwd") == 0)
		print_working_directory();
	if (ft_strcmp(core->input, "env") == 0)
		print_env_variables();
}

void	prompt_loop(t_minishell *core)
{
	using_history();
	while (TRUE)
	{
		core->error_check.file_error = FALSE;
		garbage_add(core->input = readline(get_prompt_text()));
		add_history(core->input);
		ft_strip(core->input);
		if (core->input[0] == '\0')
			continue ;
		prompt_process(core);
		clear_garbage();
		ft_clear_token();
		ft_clear_cmd_table();
	}
	rl_clear_history();
}
// tokenization();

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
