/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:42 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/05 18:50:43 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/libft/libft.h"
# include "defines.h"
# include "structs.h"
// # include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

t_minishell	*get_core(void);

// Built-in functions
void		change_directory(t_cmd *command);
void		echo(t_cmd *command);
void		print_env_variables(t_cmd *command);
void		exit_shell(t_cmd *command);
void		export_variables(t_cmd *command);
void		print_working_directory(t_cmd *command);
char		*get_working_directory(void);
void		unset(t_cmd *command);

// export functions
void		print_ordened_values(char *key, int fd);
t_bool		is_bigger(char *s1, char *s2);
char		*return_value(char *str);
char		*return_key(char *str);
void		add_end_var(t_var **var, t_var *new_var);
char		**ft_insert_str(char **arr, char *str, size_t index);
void		insert_sort(char **arr, int fd);



// Prompt functions
void		prompt_loop(t_minishell *core);
char		*get_prompt_text(void);
char		*get_hostname(void);
char		*format_hostname(char *hostname);
char		*get_username(void);
char		*get_current_dir(void);
char		*format_prompt(t_prompt *prompt);
t_bool		is_only_spaces(char *str);

// Token functions
t_tkn_type	set_tkn_type(char *str);

// Start functions
void		init_minishell(t_minishell *core);
void		get_env_vars(t_minishell *core);
t_var		*create_var(char *key, char *value);
t_var		*find_last_var(t_var *var);
t_cmd		*init_cmd_table(void);
t_prompt	init_prompt(void);
void		print_ascii(void);
void		clear_prompt(void);

// Clear functions
void		ft_error(char *str, int status);
void		ft_file_error(char *file_name, char *str, int status, size_t index);
void		ft_clear_token(void);
void		ft_clear_env_vars(void);
void		ft_clear_cmd_table(void);
void		free_variables(char *var, char **split_var);
void		ft_clear_redir_in(t_redir_in **redir_in);
void		ft_clear_redir_out(t_redir_out **redir_out);

// Redirect functions
void		handle_redirects(t_cmd *cmd, size_t index);
void		handle_here_doc(t_redir_in **redir_list, t_token *tkn,
				size_t index);
void		handle_redir_in(t_redir_in **redir_list, t_token *tkn,
				size_t index);
void		handle_redir_out(t_redir_out **redir_list, t_token *tkn,
				size_t index);
void		open_in_files(t_redir_in *redir_in);
void		open_create_out_files(t_redir_out *redir_out);
t_bool		validate_input_file(t_token *current_tkn, size_t index);
t_bool		validate_output_file(t_token *current_tkn, size_t index);
t_bool		check_file_exists(char *file_name);
t_bool		check_file_readable(char *file_name);
t_bool		check_file_writable(char *file_name);
t_bool		check_file_executable(char *file_name);
t_redir_in	*create_redir_in(t_tkn_type r_type, char *file_name);
t_redir_in	*find_last_redir_in(t_redir_in *redir);
t_redir_out	*create_redir_out(t_tkn_type r_type, char *file_name);
t_redir_out	*find_last_redir_out(t_redir_out *redir);
void		remove_unnecessary_redir_out(t_redir_out **redir_out);
void		remove_unnecessary_redir_in(t_redir_in **redir_in);
void		remove_token(t_token **token_list, t_token *target_tkn);

// Here_doc functions
void		capture_heredoc(void);
void		here_doc_loop(char *hd_limiter, int here_doc_fd);
char		*search_for_expansions(t_var *env_vars, char *line);
char		*get_var(t_var *env_vars, char *line, size_t *l_index);
size_t		get_var_len(char *line, size_t l_index);

// Expansion functions

void		check_variables(void);
char		*process_variable(char *str, int i, t_bool *in_quote);
char		*handle_var_value(char *var_name, char *var_value);
char		*replace_or_treat_quotes(char *str, char *var_name, char *var_value,
				t_bool *in_quote);
char		*tratament_quotes(char *str, char *var_name, char *var_value);
char		*look_for_variable(char *str);
char		*get_var_value(char *var_name);
int			where_is_dollar(char *str, t_bool *in_quote);
void		skip_squote(char *str, int *i);

// Debug functions
void		print_token(t_token *token);
void		print_redir_in(t_redir_in *redir_list);
void		print_redir_out(t_redir_out *redir_list);
void		print_cmd_table(t_cmd *cmd_table);
void		print_matrix(char **matrix);

// Error functions
t_bool		is_redir_token(t_token *token);

// tester functions
void		clear_garbage(void);
void		garbage_add(void *ptr);
t_bool		check_start_pipe(void);
t_bool		check_end_operators(void);
t_bool		check_spaces_between_redirections(void);
t_bool		check_spaces_between_heredoc(void);
t_bool		check_forbidden_background(void);
t_bool		check_forbidden_semicolon(void);
t_bool		check_forbidden_or(void);
t_bool		check_forbidden_and(void);
t_bool		check_close_quotes(void);
t_bool		exit_status_2(char *error_msg);
void		set_exit_status(char *error_msg);
void		skip_quotes(char *str, int *i);
void		split_input(char *str);
void		splited_add_back(t_token **head, t_token *new);
t_token		*new_token(char *str);
t_bool		lexer_and_format_prompt(void);

// Command Table functinos
void		create_cmd_table(void);
t_bool		check_for_inconsistencies(t_token *current_tkn, size_t index);
void		fill_command_node(t_token *current_tkn, size_t index);
char		*get_command(void);
char		**get_arguments(char *cmd_name);
char		**get_envp(t_var *env_vars);
char		*validate_cmd_path(char *cmd_name);
char		**get_split_path(void);
int			count_pipes(void);
int			count_args(t_token *token_list);
void		remove_token_and_redir(t_token *token, size_t index);
t_bool		is_builtin(char *cmd);

t_bool		parser(void);
t_bool		is_valid_argument(char *arg);

// Executor functions
void		command_executor(void);
void		execute_builtin(t_cmd *command, t_bool is_child);
void		execute_single_command(t_cmd *command);
void		handle_child_fds(t_cmd *command);
void		handle_execve_error(t_cmd *command);
void		wait_all_childs(t_cmd *cmd_table);

void		execute_pipelines(t_cmd *cmd_table);
void		execute_multiple_child(t_cmd *command);
void		handle_initial_proc(t_minishell *core, t_cmd *command);
void		handle_intermediate_proc(t_minishell *core, t_cmd *command);
void		handle_final_proc(t_minishell *core, t_cmd *command);
void		backup_fd_in_out(int fd_backup[2]);
void		restore_fd_in_out(void);
void		backup_pipe_fd(void);
t_bool		is_empty_cmd(t_cmd *cmd);

// Signal functions
void		ctrl_c(int sig);
void		ctrl_inverse_slash(int sig);
void		ctrl_c_here_doc(int sig);
void		sigquit_f(int sig);
void		ctrl_c_child(int sig);

// Toolbox functions

void		ft_printf_fd(int fd, const char *format, ...);
void		ft_putptr_fd(unsigned long number, char *base, int fd);
void		ft_putnbr_base_fd(long int number, char *base, int fd);

#endif