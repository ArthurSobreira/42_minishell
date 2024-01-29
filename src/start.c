/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:07:42 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/29 19:05:21 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_prompt	*init_prompt(void)
{
	t_prompt	*prompt_data;

	prompt_data = (t_prompt *)malloc(sizeof(t_prompt));
	if (!prompt_data)
		return (NULL);
	prompt_data->user = NULL;
	prompt_data->hostname = NULL;
	prompt_data->current_dir = NULL;
	prompt_data->prompt = NULL;
	return (prompt_data);
}

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

void	print_ascii(void)
{
	const char	*ascii;

	ascii = COLOR_GRAY
		"\n\t███╗░░░███╗██╗███╗░░██╗██╗░██████╗██╗░░██╗███████╗██╗░░░░░██╗░░░░░\n"
		"	████╗░████║██║████╗░██║██║██╔════╝██║░░██║██╔════╝██║░░░░░██║░░░░░\n"
		"	██╔████╔██║██║██╔██╗██║██║╚█████╗░███████║█████╗░░██║░░░░░██║░░░░░\n"
		"	██║╚██╔╝██║██║██║╚████║██║░╚═══██╗██╔══██║██╔══╝░░██║░░░░░██║░░░░░\n"
		"	██║░╚═╝░██║██║██║░╚███║██║██████╔╝██║░░██║███████╗███████╗███████╗\n"
		"	╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝╚═════╝░╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝\n\n" COLOR_RESET;
	printf("%s", ascii);
}
