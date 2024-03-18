/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:05:43 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/08 11:00:40 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

// Printf header
# include "./ft_printf/includes/ft_printf.h"

// Get_next_line header
# include "./get_next_line/includes/get_next_line.h"

// Boolean type
typedef enum e_bool
{
	FALSE,
	TRUE
}						t_bool;

// Struct for linked list
typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

typedef struct s_dlist
{
	void				*content;
	struct s_element	*next;
	struct s_element	*prev;
}						t_dlist;

typedef struct s_replace
{
	int					end;
	int					start;
}						t_replace;

// Part 1 - Libc Functions

float					ft_abs(float number);
int						ft_atoi_base(const char *str, int str_base);
int						ft_atoi(const char *nptr);
long					ft_atol(const char *nptr);
void					ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t nmemb, size_t size);
t_bool					ft_isalnum(int c);
t_bool					ft_isalpha(int c);
t_bool					ft_isascii(int c);
t_bool					ft_isatty(int fd);
t_bool					ft_isbackground(int c);
t_bool					ft_isdigit(int c);
t_bool					ft_isnumber(char *str);
t_bool					ft_ispipe(int c);
t_bool					ft_isprint(int c);
t_bool					ft_isredir(int c);
t_bool					ft_issemicolon(int c);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memset(void *s, int c, size_t n);
char					*ft_strchr(const char *s, int c);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strdup(const char *s);
char					*ft_strduplicate_char(char c);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlcpy(char *dst, const char *src,
							size_t dest_size);
size_t					ft_strlen(const char *s);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strnstr(const char *big, const char *little,
							size_t len);
char					*ft_strrchr(const char *s, int c);
int						ft_tolower(int c);
int						ft_toupper(int c);

// Part 2 - Additional Functions

char					*ft_itoa(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strtrim(char const *s1, char const *set);
char					**ft_split(char const *s, char c);

// Bonus Functions

void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstadd_front(t_list **lst, t_list *new);
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstlast(t_list *lst);
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
t_list					*ft_lstnew(void *content);
int						ft_lstsize(t_list *lst);

// Extra Functions

char					*ft_strjoin_three(char const *s1, char const *s2,
							char const *s3);
size_t					ft_matrix_len(char **matrix);
void					ft_strip(char *str);
void					ft_free_matrix(char **matrix);
void					ft_free_pointer(void **pointer);
void					ft_free(void *pointer);
char					*ft_replace(char *str, char *old, char *new);
t_bool					ft_isspace(int c);
char					*ft_strstr(const char *big, const char *little);
char					*ft_strtok(char *str, const char *delim);
size_t					ft_strncpy(char *dst, const char *src, size_t len);
size_t					ft_strspn(const char *s, const char *accept);
size_t					ft_strcspn(const char *s, const char *reject);
char					*ft_strstr_quotes(const char *big, const char *little);
char					*ft_replace_quotes(char *str, char *old, char *new);
char					*ft_strjoin_free(char *s1, char *s2);
char					*ft_replace_small(char *str, char *old, char *new,
							t_replace *rp);
char					*ft_strnew(size_t size);
char					*ft_replace_true(char *str, char *old, char *new);
char					*ft_replace_dquotes(char *str, char *old, char *new);
t_bool					is_bigger(char *s1, char *s2);

#endif