/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:18:27 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/20 14:28:16 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	readlines(t_minishell *core)
{
	char	*prompt;
	t_cmd	*command;

	command = NULL;
	using_history();
	while (1)
	{
		prompt = ft_strjoin(getenv("USER"), "@minishell: ");
		prompt = ft_strjoin(ft_strjoin(COLOR_PINK, prompt), COLOR_RESET);
		command = malloc(sizeof(t_cmd));
		if (command == NULL)
			return ;
		command->input = readline(prompt);
		free(prompt);
		add_history(command->input);
		ft_strip(command->input);
		core->command_list = ft_lstnew(command);
		ft_lstadd_back(&core->command_list, core->command_list);
		printf("input: %s\n", ((t_cmd *)(core->command_list->content))->input);
	}
	rl_clear_history();
}
