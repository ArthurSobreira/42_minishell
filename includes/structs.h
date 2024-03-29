/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:16:06 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/10 17:36:46 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_tkn_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT,
	TOKEN_REDIRECT_REVERSE,
	TOKEN_APPEND,
	TOKEN_HERE_DOC
}						t_tkn_type;

typedef enum e_proc
{
	INITIAL,
	INTERMEDIATE,
	FINAL,
}						t_proc;

enum	e_wildcard
{
	NONE,
	START,
	END,
	BOTH
};

typedef struct s_redir_in
{
	t_tkn_type			r_type;
	t_bool				here_doc;
	char				*file_name;
	int					fd_in;
	struct s_redir_in	*next;
}						t_redir_in;

typedef struct s_redir_out
{
	t_tkn_type			r_type;
	char				*file_name;
	int					fd_out;
	struct s_redir_out	*next;
}						t_redir_out;

typedef struct s_token
{
	char				*value;
	t_tkn_type			type;
	struct s_token		*next;
	struct s_token		*prev;

}						t_token;

typedef struct s_prompt
{
	char				*user;
	char				*hostname;
	char				*current_dir;
	char				*prompt;
}						t_prompt;

typedef struct s_var
{
	char				*key;
	char				*value;
	struct s_var		*next;
}						t_var;

typedef struct s_cmd
{
	pid_t				pid;
	t_bool				is_builtin;
	t_redir_in			*redir_in;
	t_redir_out			*redir_out;
	t_proc				proc_type;
	char				*cmd;
	char				**args;
	char				**envp;
	int					cmd_pos;
}						t_cmd;

typedef struct s_error
{
	t_bool				file_error[MAX_PIPELINES];
	t_bool				cmd_error[MAX_PIPELINES];
}						t_error;

typedef struct s_minishell
{
	t_cmd				*cmd_table;
	t_error				error_check;
	t_list				*gc;
	t_token				*token_list;
	t_var				*env_vars;
	t_bool				here_doc_flag;
	size_t				pipe_count;
	char				*input;
	char				**envp;
	int					env_vars_size;
	int					pipe_fd[2];
	int					fd_backup[2];
	int					exit_status;
	int					pos;
}						t_minishell;

#endif
