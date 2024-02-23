/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:09:31 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/23 11:07:08 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt_process(t_minishell *core)
{
	if (lexer_and_format_prompt())
		return ;
	capture_heredoc();
	command_executor();
	if (ft_strcmp(core->cmd_table->cmd, "exit") == 0)
		exit_shell(core->cmd_table);
	if (ft_strcmp(core->cmd_table->cmd, "pwd") == 0)
		print_working_directory(core->cmd_table);
	if (ft_strcmp(core->cmd_table->cmd, "env") == 0)
		print_env_variables(core->cmd_table);
	if (ft_strcmp(core->cmd_table->cmd, "echo") == 0)
		echo(core->cmd_table);
	if (ft_strcmp(core->cmd_table->cmd, "cd") == 0)
		change_directory(core->cmd_table);
	if (ft_strcmp(core->cmd_table->cmd, "export") == 0)
		export_variables(core->cmd_table);
	if (ft_strcmp(core->cmd_table->cmd, "unset") == 0)
		unset(core->cmd_table);
}

void	prompt_loop(t_minishell *core)
{
	using_history();
	while (TRUE)
	{
		ft_bzero(&core->error_check.file_error, MAX_PIPELINES);
		garbage_add(core->input = readline(get_prompt_text()));
		if (!core->input)
			exit_shell(core->cmd_table);
		ft_strip(core->input);
		if (core->input[0] == '\0')
			continue ;
		add_history(core->input);
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
