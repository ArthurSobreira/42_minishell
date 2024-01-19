/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:42 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/19 11:19:53 by phenriq2         ###   ########.fr       */
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
# define PROMPT_COLOR "\033[1;35m"
# define PROMPT_COLOR_RESET "\033[0m"

void	readlines(t_minishell *core);
void	built_in_array(t_minishell *core);
void	input_analysis(t_minishell *core);
void	unset(t_minishell *core);
void	change_directory(t_minishell *core);
void	echo(t_minishell *core);
void	environment(t_minishell *core);
void	exit_shell(t_minishell *core);
void	export_variables(t_minishell *core);
void	print_working_directory(t_minishell *core);
void	unset(t_minishell *core);

#endif
