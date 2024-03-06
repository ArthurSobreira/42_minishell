/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:50:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/06 17:46:21 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigquit_f(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)", STDOUT_FILENO);
		get_core()->exit_status = 131;
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_replace_line("", 0);
	}
}

void	ctrl_c_here_doc(int sig)
{
	if (sig == SIGINT)
	{
		get_core()->exit_status = 130;
		ft_putchar_fd('\n', STDOUT_FILENO);
		get_core()->flag = 0;
	}
}

void	ctrl_c_child(int sig)
{
	if (sig == SIGINT)
	{
		get_core()->exit_status = 130;
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}

void	ctrl_c(int sig)
{
	if (sig == SIGINT)
	{
		get_core()->exit_status = 130;
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

