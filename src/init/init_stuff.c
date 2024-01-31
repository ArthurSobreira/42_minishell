/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:07:42 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/31 14:05:51 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_ascii(void)
{
	const char	*ascii;

	ascii = COLOR_GRAY
		"\n\t███╗░░░███╗██╗███╗░░██╗██╗░██████╗██╗░░██╗\
███████╗██╗░░░░░██╗░░░░░\n"
		"	████╗░████║██║████╗░██║██║██╔════╝██║░░██║██\
╔════╝██║░░░░░██║░░░░░\n"
		"	██╔████╔██║██║██╔██╗██║██║╚█████╗░███████║███\
██╗░░██║░░░░░██║░░░░░\n"
		"	██║╚██╔╝██║██║██║╚████║██║░╚═══██╗██╔══██║██\
╔══╝░░██║░░░░░██║░░░░░\n"
		"	██║░╚═╝░██║██║██║░╚███║██║██████╔╝██║░░██║███\
████╗███████╗███████╗\n"
		"	╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝╚═════╝░╚═╝░░╚═╝╚══\
════╝╚══════╝╚══════╝\n\n" COLOR_RESET;
	printf("%s", ascii);
}
