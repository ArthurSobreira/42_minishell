/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:16:06 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/26 15:11:47 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct s_cmd
{
	char	*executable;
	char	**arguments;
	int		background;
}			t_cmd;

typedef	struct s_exits
{
	int				exit_code;
	char			*exit_msg;
}					t_exits;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_REDIRECTION,
	TOKEN_PIPE,
	TOKEN_BACKGROUND,
	TOKEN_HERE_DOC,
	TOKEN_OR,
	TOKEN_AND
}			t_token_type;

typedef struct s_minishell
{
	t_list	*token_list;
	t_list	*command_list;
	t_list	*input_list;
	t_list	*splited_input;
	char	*built_in[8];
	char	*input;
	t_exits exits;
}			t_minishell;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
}					t_token;

#endif
