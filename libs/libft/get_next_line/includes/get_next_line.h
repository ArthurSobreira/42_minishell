/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:32:49 by arsobrei          #+#    #+#             */
/*   Updated: 2024/01/18 17:02:06 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# ifndef CLEAR_STATIC
#  define CLEAR_STATIC -1
# endif

// Main Struct
typedef struct s_gnl
{
	char			data;
	struct s_gnl	*next;
}					t_gnl;

// Functions Prototypes
char	*get_next_line(int fd);
int		ft_sizelst(t_gnl **list_of_char, char c);
int		ft_read_error(t_gnl **main_list, char *current);
void	ft_start_gnl(t_gnl **caracter, char c);
void	ft_wipe_list(t_gnl **list_of_char, int counter);
int		ft_read_the_file(int fd, t_gnl **main_list);
int		ft_split_char(const char *c, t_gnl **main_list);
void	ft_add_caracter(t_gnl **main_list, char character);
void	ft_extract_line(t_gnl **list_of_char, char **line, int counter);

#endif