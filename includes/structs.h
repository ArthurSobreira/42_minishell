/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:16:06 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/30 12:07:03 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

typedef struct s_cmd
{
	char			*executable;
	char			**arguments;
	int				background;
}					t_cmd;

typedef struct s_exits
{
	int				exit_code;
	char			*exit_msg;
}					t_exits;

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
}					t_token_type;

typedef struct s_minishell
{
	t_list			*token_list;
	t_list			*command_list;
	t_list			*splited_input;
	char			*built_in[8];
	char			*input;
	t_exits			exits;
}					t_minishell;

typedef struct s_prompt
{
	char			*user;
	char			*hostname;
	char			*current_dir;
	char			*prompt;
}					t_prompt;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
}					t_token;

#endif
