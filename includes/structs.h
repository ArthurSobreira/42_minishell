/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:16:06 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/20 17:05:11 by phenriq2         ###   ########.fr       */
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

/**
 * @brief Estrutura que representa uma pipeline

 * @param commands Lista de comandos
 * @param num_commands Número de comandos na pipeline
*/

typedef struct s_pipeline
{
	t_cmd			**commands;
	int				num_commands;
}					t_pipeline;

/**
 * @brief Estrutura que representa um redirecionamento

 * @param file Nome do arquivo para redirecionamento
 * @param type Tipo de redirecionamento (entrada/saída)
*/

typedef struct s_redirection
{
	char			*file;
	int				type;
}					t_redirection;

/**
 * @brief Estrutura que representa um job

 * @param pipeline Sequência de comandos
 * @param input Redirecionamento de entrada
 * @param output Redirecionamento de saída
*/

typedef struct s_job
{
	t_pipeline		*pipeline;
	t_redirection	*input;
	t_redirection	*output;
}					t_job;

/**
 * @brief Estrutura que representa um ambiente

 * @param variables Lista de variáveis de ambiente
 * @param size Número de variáveis de ambiente
 * @param capacity Capacidade máxima da lista de variáveis
*/

typedef struct s_env
{
	char			**variables;
	int				size;
	int				capacity;
}					t_env;

/**
 * @brief Estrutura que representa um processo

 * @param pid PID do processo
 * @param status Status do processo
*/

typedef struct s_process
{
	pid_t			pid;
	int				status;
}					t_process;

/**
 * @brief Estrutura que contem o signal
 * @param action Ação a ser executada
 */

typedef struct s_minishell
{
	t_env			*env;
	t_pipeline		*pipeline;
	t_redirection	*redirection;
	t_job			*job;
	t_process		*process;
	t_list			*token_list;
	t_list			*command_list;
	char			*built_in[8];
	char			*input;
}					t_minishell;

#endif
