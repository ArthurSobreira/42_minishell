/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:11:54 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/18 12:16:17 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_gnl
{
	char			data;
	struct s_gnl	*next;
}					t_gnl;

char				*get_next_line(int fd);
int					ft_sizelst(t_gnl **list_of_char, char c);
int					ft_read_error(t_gnl **main_list, char *current);
void				ft_start_gnl(t_gnl **caracter, char c);
void				ft_wipe_list(t_gnl **list_of_char, int counter);
int					ft_read_the_file(int fd, t_gnl **main_list);
int					ft_split_char(const char *c, t_gnl **main_list);
void				ft_add_caracter(t_gnl **main_list, char character);
void				ft_extract_line(t_gnl **list_of_char, char **line,
						int counter);

#endif
