/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:35:52 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/09 18:20:03 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(t_cmd *command, char *message)
{
	if (!ft_strcmp(command->cmd, "exit"))
		ft_putendl_fd(message, STDERR_FILENO);
}

static t_bool	verify_long_max(t_minishell *core, t_cmd *command)
{
	if (ft_isnumber(command->args[1]) && \
		((command->args[1][0] == '-' && ft_strlen(command->args[1]) <= 20) || \
		(command->args[1][0] != '-' && ft_strlen(command->args[1]) <= 19)))
	{
		if ((ft_strlen(command->args[1]) == 19 && \
			ft_strcmp(command->args[1], "9223372036854775807") > 0) || \
			(ft_strlen(command->args[1]) == 20 && \
			ft_strcmp(command->args[1], "-9223372036854775808") > 0))
		{
			print_error(command, "minishell: exit: numeric argument required");
			core->exit_status = SYNTAX_ERROR;
			return (TRUE);
		}
		core->exit_status = ft_atoi(command->args[1]);
	}
	else if (command && (!ft_isnumber(command->args[1]) || \
		(command->args[1][0] == '-' && ft_strlen(command->args[1]) > 20) || \
		(command->args[1][0] != '-' && ft_strlen(command->args[1]) > 19)))
	{
		print_error(command, "minishell: exit: numeric argument required");
		core->exit_status = SYNTAX_ERROR;
	}
	return (TRUE);
}

static t_bool	validate_args(t_minishell *core, t_cmd *command)
{
	if (command && ft_matrix_len(command->args) > 2)
	{
		if (!ft_isnumber(command->args[1]))
		{
			print_error(command, "minishell: exit: numeric argument required");
			core->exit_status = SYNTAX_ERROR;
			return (TRUE);
		}
		else
			print_error(command, "minishell: exit: too many arguments");
		core->exit_status = EXIT_FAILURE;
		return (FALSE);
	}
	if (command && ft_matrix_len(command->args) == 2)
	{
		if (!verify_long_max(core, command))
			return (FALSE);
	}
	return (TRUE);
}

void	exit_shell(t_cmd *command)
{
	t_minishell	*core;

	core = get_core();
	if (command && !ft_strcmp(command->cmd, "exit") && command->args[1])
		if (!validate_args(core, command))
			return ;
	if (core->token_list != NULL)
		ft_clear_token();
	if (core->env_vars != NULL)
		ft_clear_env_vars();
	if (core->cmd_table != NULL)
		ft_clear_cmd_table();
	clear_garbage();
	rl_clear_history();
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close_all_fds();
	unlink(HERE_DOC_FILE);
	exit(core->exit_status);
}
