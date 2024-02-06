/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_coisas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:39:32 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/06 19:08:36 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		printf("type: %d\n", tmp->type);
		printf("value: %s\n", tmp->value);
		tmp = tmp->next;
	}
}

void	print_splited(t_input *input)
{
	while (input)
	{
		printf("%s\n", input->content);
		input = input->next;
	}
}
