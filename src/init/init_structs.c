/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:31:03 by arsobrei          #+#    #+#             */
/*   Updated: 2024/01/30 11:26:35 by arsobrei         ###   ########.fr       */
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
