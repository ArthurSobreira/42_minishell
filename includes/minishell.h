/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:42 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/12 17:33:16 by phenriq2         ###   ########.fr       */
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

t_minishell	*get_core(void);

// Built-in functions
char		*get_working_directory(void);
void		print_working_directory(void);
void		print_env_variables(void);

void		unset(t_minishell *core);
void		change_directory(t_minishell *core);
void		echo(void);
void		exit_shell(void);
void		export_variables(t_minishell *core);
void		unset(t_minishell *core);

// Prompt functions
void		prompt_loop(void);
char		*get_prompt_text(void);
char		*get_hostname(void);
char		*format_hostname(char *hostname);
char		*get_username(void);
char		*get_current_dir(void);
char		*format_prompt(t_prompt *prompt);

// Token functions
void		tokenization(void);
t_tkn_type	set_tkn_type(char *str);
// void		split_input(void);
void		process_non_space(t_minishell *core, int *i);
void		add_to_list(t_minishell *core, int start, int end);
t_bool		is_redir_token(t_token *token);
t_bool		isall(t_minishell *core, int *i);
void		ft_clear_splited_input(void);

// Start functions
void		init_minishell(t_minishell *core);
void		get_env_vars(t_minishell *core);
t_var		*create_var(char *key, char *value);
t_var		*find_last_var(t_var *var);
t_prompt	init_prompt(void);
void		print_ascii(void);
void		clear_prompt(void);

// Clear functions
void		ft_error(char *str, int status);
void		ft_clear_token(void);
void		ft_clear_env_vars(void);
void		ft_clear_splited_input(void);
void		ft_clear_redir_in(t_redir_in **redir_in);
void		ft_clear_redir_out(t_redir_out **redir_out);

// Redirect functions
void		handle_redirects(void);
void		handle_redir_in(t_redir_in **redir_list, t_token *current_tkn);
void		handle_redir_out(t_redir_out **redir_list, t_token *current_tkn);
void		validate_input_file(t_token *current_tkn);
void		validate_output_file(t_token *current_tkn);
void		open_create_out_files(t_redir_out *redir_out);
t_bool		check_file_exists(char *file_name);
t_bool		check_file_readable(char *file_name);
t_bool		check_file_writable(char *file_name);
t_bool		check_file_executable(char *file_name);
t_redir_in	*create_redir_in(t_tkn_type r_type, char *file_name);
t_redir_in	*find_last_redir_in(t_redir_in *redir);
t_redir_out	*create_redir_out(t_tkn_type r_type, char *file_name);
t_redir_out	*find_last_redir_out(t_redir_out *redir);
void		remove_redir_token(t_token **token_list, t_token *target_tkn);

// Here_doc functions
void		handle_here_doc(t_redir_in **redir_list, t_token *current_tkn);

// Expansion functions

void		look_for_variables(void);

// Debug functions
void		print_token(t_token *token);
void		print_splited(t_input *input);
void		print_redir_in(t_redir_in *redir_list);
void		print_redir_out(t_redir_out *redir_list);

// Error functions

void		search_bad_redirects(char *str);
t_bool		is_excluded_type(t_tkn_type type, int option);

// Parser functions

void		parser(void);
t_bool		search_bugs(void);
t_bool		pipe_and_operator_error(void);

// tester functions
void		clear_garbage(void);
void		garbage_add(void *ptr);
t_bool		check_start_pipe(void);
t_bool		check_end_operators(void);
t_bool		check_spaces_between_redirections(void);
t_bool		check_spaces_between_heredock(void);
char		*check_input_error(void);
t_bool		check_forbidden_background(void);
t_bool		check_forbidden_semicolon(void);
t_bool		check_forbidden_or(void);
t_bool		check_forbidden_and(void);
t_bool		check_close_quotes(void);
t_bool		exit_status_2(char *error_msg);
void		set_exit_status(char *error_msg);
void		skip_quotes(char *str, int *i);
void		replace_input(void);
void		split_input(char *str);
void		splited_add_back(t_token **head, t_token *new);
t_token		*new_token(char *str);
char		*parser_and_split(void);

#endif