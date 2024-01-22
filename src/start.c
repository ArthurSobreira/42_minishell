/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:07:42 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/22 11:59:11 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	built_in_array(t_minishell *core)
{
	core->splited_input = NULL;
	core->built_in[0] = "echo";
	core->built_in[1] = "cd";
	core->built_in[2] = "pwd";
	core->built_in[3] = "export";
	core->built_in[4] = "unset";
	core->built_in[5] = "env";
	core->built_in[6] = "exit";
	core->built_in[7] = NULL;
}
