/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:16:06 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/22 13:06:24 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"
#define TOKEN "|>"

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct s_cmd
{
	char			*executable;
	char			**arguments;
	int				background;
}					t_cmd;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_REDIRECTION,
	TOKEN_PIPE,
	TOKEN_BACKGROUND,
	TOKEN_HERE_DOC,
	TOKEN_OR,
	TOKEN_AND,
	TOKEN_SINGLE_QUOTE,
	TOKEN_DOUBLE_QUOTE,
}					t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	t_bool			s_quote;
	t_bool			d_quote;
}					t_token;

typedef struct s_minishell
{
	t_list			*token_list;
	t_list			*command_list;
	t_list			*splited_input;
	char			*built_in[8];
	char			*input;
}					t_minishell;

#endif
