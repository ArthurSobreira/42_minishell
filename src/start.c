/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:07:42 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/18 11:50:53 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	built_in_array(t_minishell *core)
{
	core->built_in[0] = "echo";
	core->built_in[1] = "cd";
	core->built_in[2] = "pwd";
	core->built_in[3] = "export";
	core->built_in[4] = "unset";
	core->built_in[5] = "env";
	core->built_in[6] = "exit";
	core->built_in[7] = NULL;
}
