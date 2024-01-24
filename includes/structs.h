/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:16:06 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/24 15:05:41 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"
# define QUOTE "'\""

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

/**
 * @brief Estrutura que representa um comando

 * @param executable Nome do executável
 * @param arguments Argumentos do comando
 * @param background Flag que indica se o comando deve
 *  executado em background
*/
typedef struct s_cmd
{
	char			*executable;
	char			**arguments;
	int				background;
}					t_cmd;

/**
 * @brief Enumeração que representa o tipo de token
 * @param TOKEN_WORD Palavra
 * @param TOKEN_REDIRECTION Redirecionamento (<, >, >>)
 * @param TOKEN_PIPE Pipe (|)
 * @param TOKEN_BACKGROUND Background (&)
 */
typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_REDIRECTION,
	TOKEN_PIPE,
	TOKEN_BACKGROUND,
	TOKEN_HERE_DOC,
	TOKEN_OR,
	TOKEN_AND,
	TOKEN_NEWLINE,
	TOKEN_EOF
}					t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
}					t_token;

typedef	struct s_exits
{
	int				exit_code;
	char			*exit_msg;
}					t_exits;

typedef struct s_minishell
{
	t_list			*token_list;
	t_list			*command_list;
	char			*built_in[8];
	char			*input;
	t_list			*splited_input;
	t_exits			exits;
}					t_minishell;

#endif
