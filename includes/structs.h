/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:16:06 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/17 16:00:16 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

/**
 * @brief Estrutura que representa um comando

 * @param executable Nome do executável
 * @param arguments Argumentos do comando
 * @param background Flag que indica se o comando deve
 *  executado em background
*/
typedef struct s_command
{
	char				*executable;
	char				**arguments;
	char				**env;
	int					background;
	struct s_command	*next;
}						t_command;

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
	TOKEN_HERE_DOC
}						t_token_type;

typedef struct s_token
{
	char				*value;
	t_token_type		type;
}						t_token;

/**
 * @brief Estrutura que representa uma pipeline

 * @param commands Lista de comandos
 * @param num_commands Número de comandos na pipeline
*/

typedef struct s_pipeline
{
	t_command			**commands;
	int					num_commands;
}						t_pipeline;

/**
 * @brief Estrutura que representa um redirecionamento

 * @param file Nome do arquivo para redirecionamento
 * @param type Tipo de redirecionamento (entrada/saída)
*/

typedef struct s_redirection
{
	char				*file;
	int					type;
}						t_redirection;

/**
 * @brief Estrutura que representa um job

 * @param pipeline Sequência de comandos
 * @param input Redirecionamento de entrada
 * @param output Redirecionamento de saída
*/

typedef struct s_job
{
	t_pipeline			*pipeline;
	t_redirection		*input;
	t_redirection		*output;
}						t_job;

/**
 * @brief Estrutura que representa um ambiente

 * @param variables Lista de variáveis de ambiente
 * @param size Número de variáveis de ambiente
 * @param capacity Capacidade máxima da lista de variáveis
*/

typedef struct s_environment
{
	char				**variables;
	int					size;
	int					capacity;
}						t_environment;

/**
 * @brief Estrutura que representa um processo

 * @param pid PID do processo
 * @param status Status do processo
*/

typedef struct s_process
{
	pid_t				pid;
	int					status;
}						t_process;

/**
 * @brief Estrutura que contem o signal
 * @param action Ação a ser executada
 */

typedef struct s_minishell
{
	t_environment		*env;
	t_command			*command;
	t_pipeline			*pipeline;
	t_redirection		*redirection;
	t_job				*job;
	t_process			*process;
	t_token				input[1024];
	char				*built_in[8];
}						t_minishell;

#endif
