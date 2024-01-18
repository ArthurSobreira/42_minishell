/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:18:27 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/18 17:23:48 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	token_type(t_minishell *core, int capacity)
{
	int	i;

	i = -1;
	while (++i < capacity)
	{
		if (ft_strcmp(core->input[i].value, "|") == 0)
			core->input[i].type = TOKEN_PIPE;
		else if (ft_strcmp(core->input[i].value, "<") == 0)
			core->input[i].type = TOKEN_REDIRECTION;
		else if (ft_strcmp(core->input[i].value, ">") == 0)
			core->input[i].type = TOKEN_REDIRECTION;
		else if (ft_strcmp(core->input[i].value, ">>") == 0)
			core->input[i].type = TOKEN_REDIRECTION;
		else if (ft_strcmp(core->input[i].value, "&") == 0)
			core->input[i].type = TOKEN_BACKGROUND;
		else
			core->input[i].type = TOKEN_WORD;
	}
}

static void	parse_input(char *input, t_minishell *core)
{
	char	**commands;
	int		len;
	int		i;

	i = -1;
	commands = ft_split(input, ' ');
	len = 0;
	while (commands[len])
		len++;
	while (++i < len)
		core->input[i].value = commands[i];
	core->input[i].value = NULL;
	free(commands);
	token_type(core, len);
}

void	readlines(t_minishell *core)
{
	char	*input;

	using_history();
	while (1)
	{
		input = readline("MiniShell: ");
		add_history(input);
		parse_input(input, core);
		input_analysis(core);
		free(input);
	}
	rl_clear_history();
}
