/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:28:25 by arsobrei          #+#    #+#             */
/*   Updated: 2024/01/30 12:12:57 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isalnum(int c)
{
	if (ft_isalpha(c))
	{
		return(TRUE);
	}
	else if (ft_isdigit(c))
	{
		return(TRUE);
	}
	else
	{
		return (FALSE);
	}
}
