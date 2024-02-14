/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:48:00 by arsobrei          #+#    #+#             */
/*   Updated: 2024/02/13 19:27:57 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

// Colors
# define COLOR_PINK "\001\x1B[1;35m\002"
# define COLOR_GREEN "\001\x1B[1;32m\002"
# define COLOR_RED "\001\x1B[1;31m\002"
# define COLOR_BLUE "\001\x1B[34m\002"
# define COLOR_YELLOW "\001\x1B[1;33m\002"
# define COLOR_CYAN "\001\x1B[36m\002"
# define COLOR_WHITE "\001\x1B[1;37m\002"
# define COLOR_BLACK "\001\x1B[1;30m\002"
# define COLOR_GRAY "\001\x1B[1;90m\002"
# define COLOR_RESET "\001\x1B\033[0m\002"

# define END_FILE "syntax error: unexpected end of file"
# define FORBIDDEN_AND "syntax error: unexpected token `&&'"
# define FORBIDDEN_OR "syntax error: unexpected token `||'"
# define FORBIDDEN_SEMICOLON "syntax error: unexpected token `;'"
# define FORBIDDEN_BACKGROUND "syntax error: unexpected token `&'"
# define FORBIDDEN_PIPE "syntax error: unexpected token `|'"
# define FORBIDDEN_REDIR "syntax error: unexpected token `>'"
# define FORBIDDEN_REDIR_REVERSE "syntax error: unexpected token `<'"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define SYNTAX_ERROR 2
# define PERMISSION_ERROR 126

# define MAX_PATH_LEN 4096
# define MAX_HOSTNAME_LEN 256
# define MAX_VAR_LEN 4096
# define HERE_DOC_FILE "minishell_here_doc"

#endif