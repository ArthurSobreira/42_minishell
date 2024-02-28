/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:50:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/28 12:16:32 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	ctrl_inverse_slash(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", STDOUT_FILENO);
		get_core()->exit_status = 131;
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}
