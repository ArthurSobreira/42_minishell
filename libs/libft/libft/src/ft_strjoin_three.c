/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:41:00 by arsobrei          #+#    #+#             */
/*   Updated: 2024/01/29 09:55:35 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(s1, s2);
	result = ft_strjoin(temp, s3);
	ft_free_pointer((void *)&temp);
	return (result);
}
