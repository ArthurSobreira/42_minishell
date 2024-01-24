/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:42 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/24 15:27:55 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/libft/libft.h"
# include "structs.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>

# define COLOR_PINK "\033[1;35m"
# define COLOR_RESET "\033[0m"
# define COLOR_GREEN "\033[1;32m"
# define COLOR_RED "\033[1;31m"
# define COLOR_BLUE "\033[1;34m"
# define COLOR_YELLOW "\033[1;33m"
# define COLOR_CYAN "\033[1;36m"
# define COLOR_WHITE "\033[1;37m"
# define COLOR_BLACK "\033[1;30m"
# define COLOR_GRAY "\033[1;90m"

void	readlines(t_minishell *core);
void	built_in_array(t_minishell *core);
void	execute_builtin(t_minishell *core);
void	unset(t_minishell *core);
void	change_directory(t_minishell *core);
void	echo(t_minishell *core);
void	environment(t_minishell *core);
void	exit_shell(t_minishell *core);
void	export_variables(t_minishell *core);
void	print_working_directory(t_minishell *core);
void	unset(t_minishell *core);
void	ft_strip(char *str);
void	split_quote(t_minishell *core);
void	re_parse(t_minishell *core);
t_bool	ispipe(int c);
t_bool	isredir(int c);
t_bool	isbackground(int c);
t_bool	issemicolon(int c);
t_bool	isnull(int c);

#endif
