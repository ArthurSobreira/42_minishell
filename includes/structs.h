/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:16:06 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/02 18:57:34 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_tkn_type
{
	TOKEN_WORD,
	TOKEN_REDIRECT,
	TOKEN_REDIRECT_REVERSE,
	TOKEN_APPEND,
	TOKEN_PIPE,
	TOKEN_HERE_DOC,
	TOKEN_QUOTE,
	TOKEN_BACKGROUND,
	TOKEN_SEMICOLON,
	TOKEN_OR,
	TOKEN_AND
}						t_tkn_type;


typedef struct s_var
{
	char				*key;
	char				*value;
	struct s_var		*next;
}						t_var;

typedef struct s_exits
{
	int					exit_code;
	char				*exit_msg;
}						t_exits;

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

typedef struct s_counter
{
	int					pipes;
	int					redir;
	int					here_doc;
}						t_counter;

typedef struct s_minishell
{
	t_token				*token_list;
	t_input				*splited_input;
	t_var				*env_vars;
	int					env_vars_size;
	char				*built_in[8];
	char				*input;
	char				**envp;
	t_exits				exits;
	t_counter			counter;
}						t_minishell;

#endif
