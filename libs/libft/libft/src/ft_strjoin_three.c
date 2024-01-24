/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:41:00 by arsobrei          #+#    #+#             */
/*   Updated: 2024/01/24 15:42:56 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	result = ft_strjoin(result, s3);
	return (result);
}

