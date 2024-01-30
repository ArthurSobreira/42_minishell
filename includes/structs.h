/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:16:06 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/30 14:51:55 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

typedef struct s_cmd
{
	char				*executable;
	char				**arguments;
	int					background;
}						t_cmd;

typedef struct s_exits
{
	int					exit_code;
	char				*exit_msg;
}						t_exits;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_REDIRECT,
	TOKEN_REDIRECT_REVERSE,
	TOKEN_APPEND,
	TOKEN_PIPE,
	TOKEN_HERE_DOC,
	TOKEN_QUOTE,
	TOKEN_BACKGROUND,
	TOKEN_OR,
	TOKEN_AND
}						t_token_type;

typedef struct s_list_ms
{
	char				*content;
	struct s_list_ms	*next;
}						t_list_ms;
typedef struct s_token
{
	char				*value;
	t_token_type		type;
	struct s_token		*next;

}						t_token;

typedef struct s_prompt
{
	char				*user;
	char				*hostname;
	char				*current_dir;
	char				*prompt;
}						t_prompt;

typedef struct s_minishell
{
	t_token				*token_list;
	t_list_ms			*splited_input;
	char				*built_in[8];
	char				*input;
	t_exits				exits;
}						t_minishell;

#endif