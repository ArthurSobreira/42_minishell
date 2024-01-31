/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:42 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/31 19:01:23 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/libft/libft.h"
# include "structs.h"
# include "defines.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

t_minishell		*get_core(void);

// Built-in functions
char			*get_working_directory(void);
void			print_working_directory(void);
void			print_env_variables(void);

void			unset(t_minishell *core);
void			change_directory(t_minishell *core);
void			echo(void);
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
t_tkn_type		set_token_type(char *str);
void			split_input(t_minishell *core);
void			process_non_space(t_minishell *core, int *i);
void			add_to_list(t_minishell *core, int start, int end);
t_bool			isall(t_minishell *core, int *i);
void			ft_clear_splited_input(void);
void			ft_clear_splited_input(void);

// Start functions
t_minishell		*init_minishell(char *envp[]);
t_prompt		init_prompt(void);
void			clear_prompt(void);
void			print_ascii(void);

#endif