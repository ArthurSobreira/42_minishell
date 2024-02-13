/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:16:06 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/12 22:14:43 by arsobrei         ###   ########.fr       */
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
	TOKEN_HERE_DOC,
	TOKEN_SQUOTE,
	TOKEN_DQUOTE,
	TOKEN_VARIABLE,
	TOKEN_BACKGROUND,
	TOKEN_SEMICOLON,
	TOKEN_OR,
	TOKEN_AND,
}						t_tkn_type;

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

typedef struct s_input
{
	char				*content;
	struct s_input		*next;
}						t_input;

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
	char				*executable;
	char				**arguments;
	t_redir_in			*redir_in;
	t_redir_out			*redir_out;
}						t_cmd;

typedef struct s_minishell
{
	t_token				*token_list;
	t_input				*splited_input;
	t_var				*env_vars;
	t_cmd				*cmd_list;
	int					env_vars_size;
	int					exit_status;
	char				*built_in[8];
	char				*input;
	char				**envp;
	t_bool				file_error;
}						t_minishell;

#endif
