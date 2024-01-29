/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:34:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/29 17:19:18 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_strip(char *str)
{
	size_t	len;
	size_t	start;
	size_t	end;

	if (str == NULL || *str == '\0')
		return ;
	len = ft_strlen(str);
	start = 0;
	end = len - 1;
	while (start < len && (str[start] == ' ' || str[start] == '\t'
			|| str[start] == '\n' || str[start] == '\v' || str[start] == '\f'
			|| str[start] == '\r'))
		start++;
	while (end > start && (str[end] == ' ' || str[end] == '\t'
			|| str[end] == '\n' || str[end] == '\v' || str[end] == '\f'
			|| str[end] == '\r'))
		end--;
	ft_memmove(str, str + start, end - start + 1);
	str[end - start + 1] = '\0';
}

void	ft_error(char *str, int status)
{
	t_minishell	*core;

	core = get_core();
	ft_putstr_fd(str, STDERR_FILENO);
	ft_free(core->input);
	rl_clear_history();
	exit(status);
}
