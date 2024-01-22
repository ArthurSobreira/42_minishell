/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:15:36 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/22 11:59:54 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	splite_input(t_minishell *core)
{
	char	*spl;
	t_bool	quote;
	int		start;
	int		end;
	int		i;

	quote = FALSE;
	start = 0;
	i = 0;
	spl = core->input;
	while (spl[i])
	{
		if (spl[i] == '\'' || spl[i] == '\"')
			quote = !quote;
		if (ft_isspace(spl[i]) && !quote && (ft_isspace(spl[i + 1])))
		{
			end = i;
			ft_lstadd_back(&core->splited_input, ft_lstnew(ft_substr(spl, start,
						end - start)));
			start = i + 1;
		}
		i++;
	}
	ft_lstadd_back(&core->splited_input, ft_lstnew(ft_substr(spl, start, end
				- start)));
}
