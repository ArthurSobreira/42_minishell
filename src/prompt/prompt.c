/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:09:31 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/07 11:17:32 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt_process(void)
{
	if (is_only_spaces(get_core()->input))
		return ;
	if (lexer_and_format_prompt())
		return ;
	if (parser())
		return ;
	capture_heredoc();
	if (get_core()->here_doc_flag)
		return ;
	command_executor();
}

void	prompt_loop(t_minishell *core)
{
	using_history();
	while (TRUE)
	{
		signal(SIGINT, ctrl_c);
		signal(SIGQUIT, SIG_IGN);
		core->here_doc_flag = FALSE;
		ft_bzero(&core->error_check.file_error, MAX_PIPELINES);
		ft_bzero(&core->error_check.cmd_error, MAX_PIPELINES);
		garbage_add(core->input = readline(get_prompt_text()));
		if (!is_only_spaces(core->input))
			add_history(core->input);
		if (!core->input)
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			exit_shell(NULL);
		}
		if (core->input[0] == '\0')
			continue ;
		prompt_process();
		clear_garbage();
		ft_clear_token();
		ft_clear_cmd_table();
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
	garbage_add(prompt_data.prompt);
	return (prompt_data.prompt);
}

t_bool	is_only_spaces(char *str)
{
	if (!str)
		return (TRUE);
	while (*str)
	{
		if (!ft_isspace(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
