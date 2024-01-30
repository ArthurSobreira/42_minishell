/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:52:22 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/30 15:26:03 by phenriq2         ###   ########.fr       */
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
# define COLOR_BLUE "\033[34m"
# define COLOR_YELLOW "\033[1;33m"
# define COLOR_CYAN "\033[36m"
# define COLOR_WHITE "\033[1;37m"
# define COLOR_BLACK "\033[1;30m"
# define COLOR_GRAY "\033[1;90m"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define MAX_PATH_LEN 4096
# define MAX_HOSTNAME_LEN 256

t_minishell		*get_core(void);

// Built-in functions
char			*get_working_directory(void);
void			print_working_directory(void);

void			unset(t_minishell *core);
void			change_directory(t_minishell *core);
void			echo(void);
void			environment(t_minishell *core);
void			exit_shell(void);
void			export_variables(t_minishell *core);
void			unset(t_minishell *core);
void			ft_error(char *str, int status);

// Prompt functions
void			prompt_loop(t_minishell *core);
char			*get_prompt_text(t_minishell *core);
char			*get_hostname(t_minishell *core);
char			*format_hostname(char *hostname);
char			*get_username(void);
char			*get_current_dir(void);
char			*format_prompt(t_prompt *prompt);

// Token functions
void			tokenization(t_minishell *core);
t_token_type	set_token_type(char *str);
void			split_input(t_minishell *core);
void			process_non_space(t_minishell *core, int *i);
void			add_to_list(t_minishell *core, int start, int end);
t_bool			isall(t_minishell *core, int *i);
void			ft_clear_splited_input(void);
void			ft_clear_splited_input(void);

// Start functions
t_prompt		init_prompt(void);
void			built_in_array(t_minishell *core);

void			print_ascii(void);

#endif