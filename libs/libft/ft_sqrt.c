/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:05:05 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/16 11:20:53 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	raiz;
	int	z;

	raiz = nb;
	if (raiz < 1)
		return (0);
	while (1)
	{
		z = (raiz + nb / raiz) / 2;
		if (z == raiz)
			break ;
		raiz = z;
	}
	if ((raiz * raiz) == nb)
		return (raiz);
	else
		return (0);
}
