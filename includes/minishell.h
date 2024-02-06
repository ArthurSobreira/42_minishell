/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:42 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/06 19:45:13 by phenriq2         ###   ########.fr       */
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
void			print_env_variables(void);

void			unset(t_minishell *core);
void			change_directory(t_minishell *core);
void			echo(void);
void			exit_shell(void);
void			export_variables(t_minishell *core);
void			unset(t_minishell *core);

// Prompt functions
void		prompt_loop(t_minishell *core);
char		*get_prompt_text(void);
char		*get_hostname(void);
char		*format_hostname(char *hostname);
char		*get_username(void);
char		*get_current_dir(void);
char		*format_prompt(t_prompt *prompt);

// Token functions
void		tokenization(void);
t_tkn_type	set_tkn_type(char *str);
void		split_input(void);
void		process_non_space(t_minishell *core, int *i);
void		add_to_list(t_minishell *core, int start, int end);
t_bool		isall(t_minishell *core, int *i);
void		ft_clear_splited_input(void);
void		search_bugs(void);

// Start functions
void			init_minishell(t_minishell *core);
void			get_env_vars(t_minishell *core);
t_var			*create_var(char *key, char *value);
t_var			*find_last_var(t_var *var);
t_prompt		init_prompt(void);
void			print_ascii(void);
void			clear_prompt(void);

// Clear functions
void		ft_error(char *str, int status);
void		ft_clear_token(void);
void		ft_clear_env_vars(void);
void		ft_clear_splited_input(void);
void			ft_clear_redir_in(t_redir_in **redir_in);
void			ft_clear_redir_out(t_redir_out **redir_out);

// Redirect functions
void			handle_redirects(void);
void			handle_redir_out(t_redir_out **redir_list, t_token *current_tkn);
void			validate_io_files(t_token *token_list);
void			validate_input_file(t_token *current_tkn);
void			validate_output_file(t_token *current_tkn);
t_bool				check_file_exists(char *file_name);
t_bool			check_file_readable(char *file_name);
t_bool				check_file_writable(char *file_name);
t_bool			check_file_executable(char *file_name);
t_redir_in		*create_redir_in(t_tkn_type r_type, char *file_name);
t_redir_in		*find_last_redir_in(t_redir_in *redir);
t_redir_out		*create_redir_out(t_tkn_type r_type, char *file_name);
t_redir_out		*find_last_redir_out(t_redir_out *redir);
void			remove_redir_token(t_token **token_list, t_token *target_tkn);

void	print_token(t_token *token);

// Expansion functions

void		look_for_variables(void);

// Debug functions

void		print_token(t_token *token);
void		print_splited(t_input *input);

#endif