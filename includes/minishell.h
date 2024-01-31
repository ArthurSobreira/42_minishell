/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:42 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/31 19:05:59 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/libft/libft.h"
# include "defines.h"
# include "structs.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

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
void			tokenization(void);
t_tkn_type		set_tkn_type(char *str);
void			split_input(void);
void			process_non_space(t_minishell *core, int *i);
void			add_to_list(t_minishell *core, int start, int end);
t_bool			isall(t_minishell *core, int *i);
void			ft_clear_splited_input(void);
void			searsh_bugs(void);

// Start functions
t_minishell		*init_minishell(char *envp[]);
t_prompt		init_prompt(void);
void			clear_prompt(void);
void			print_ascii(void);

#endif