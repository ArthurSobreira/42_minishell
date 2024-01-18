/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:20:07 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/26 15:42:29 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_extract_line(t_gnl **list_of_char, char **line, int counter)
{
	t_gnl	*current;
	int		index;

	current = *list_of_char;
	index = 0;
	while (index < counter && current != NULL)
	{
		(*line)[index] = current->data;
		current = current->next;
		index++;
	}
	(*line)[index] = '\0';
}

void	ft_add_caracter(t_gnl **main_list, char character)
{
	t_gnl	*new_node;
	t_gnl	*current;

	if (main_list == NULL || *main_list == NULL)
		return ;
	new_node = (t_gnl *)malloc(sizeof(t_gnl));
	if (new_node == NULL)
		return ;
	new_node->data = character;
	new_node->next = NULL;
	current = *main_list;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

int	ft_split_char(const char *c, t_gnl **main_list)
{
	int	bol;

	bol = 1;
	while (*c)
	{
		if (*c == '\n')
			bol = 0;
		if (*main_list == NULL)
		{
			ft_start_gnl(main_list, *c);
			c++;
			continue ;
		}
		ft_add_caracter(main_list, *c);
		c++;
	}
	return (bol);
}

int	ft_read_the_file(int fd, t_gnl **main_list)
{
	int		bytesread;
	char	*current;

	current = malloc(BUFFER_SIZE + 1);
	if (!current)
		return (1);
	bytesread = 1;
	while (bytesread)
	{
		bytesread = read(fd, current, BUFFER_SIZE);
		if (bytesread < 0)
			return (ft_read_error(main_list, current));
		if (bytesread == 0)
		{
			free(current);
			return (1);
		}
		current[bytesread] = '\0';
		if (ft_split_char(current, main_list) == 0)
			break ;
	}
	free(current);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_gnl	*main_list;
	char			*line;
	int				counter;

	if (((fd < 0) && !main_list) || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_read_the_file(fd, &main_list) && !main_list)
		return (NULL);
	counter = ft_sizelst(&main_list, '\n');
	line = malloc(counter + 1);
	if (!line)
	{
		ft_wipe_list(&main_list, -1);
		return (NULL);
	}
	ft_extract_line(&main_list, &line, counter);
	ft_wipe_list(&main_list, counter);
	return (line);
}
