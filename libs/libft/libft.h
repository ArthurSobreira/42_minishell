/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:11:54 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/08 10:43:28 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// STRUCTS LIBFT
typedef struct s_bonus
{
	void			*value;
	struct s_bonus	*next;
}					t_list;

typedef struct s_itoa_base
{
	char			*str;
	size_t			len;
	int				len_base;
}					t_variables;

typedef struct s_split
{
	char			**s_string;
	int				len_subs;
	int				i;
}					t_var;

// STRUCTS GNL

typedef struct s_gnl
{
	char			data;
	struct s_gnl	*next;
}					t_gnl;

// FUNCTIONS IS LIBFT
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isnonzero_digit(int c);
int					ft_strisnumber(char *str);

// FUNCTIONS TO LIBFT
int					ft_toupper(int c);
long				ft_atol(const char *nptr);
int					ft_tolower(int c);
char				*ft_itoa(int n);
char				*ft_itoa_base(long int nbr, char *base);
char				*ft_itoa_unsigned(unsigned int n);

// FUNCTIONS STR LIBFT
size_t				ft_strlen(const char *msg);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strdup(char *src);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strnew(int counter);
void				ft_strrev(char *ptr);
size_t				ft_count_words(char const *s, char c);
int					ft_strcmp(char *s1, char *s2);

// FUNCTIONS MEM LIBFT
void				*ft_memset(void *array, int value, size_t num);
void				ft_bzero(void *array, size_t num);
void				*ft_memcpy(void *array, const void *src, size_t num);
void				*ft_memmove(void *array, const void *src, size_t num);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t num_elements, size_t element_size);

// FUNCTIONS PUT LIBFT
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_putstr(const char *s);
size_t				ft_putnbr(long int n);
size_t				ft_putnbr_base(long int nbr, char *base);
void				ft_putendl(char *s);
int					ft_putptr(size_t number, char *base);
int					ft_putchar(char c);

// FUNCTIONS LIST LIBFT
t_list				*ft_lstnew(void *value);
void				ft_lstadd_front(t_list **lst, t_list *newnode);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *newnode);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// FUNCTIONS MATH LIBFT
size_t				ft_nbrlen(long int nbr);
size_t				ft_nbrlen_base(long int nbr, int len_base);
int					ft_sqrt(int nb);
int					ft_pow(int nb, int power);
int					ft_matrixlen(char **matrix);
void				ft_matrixdel(char **matrix);

// FUNCTIONS GNL LIBFT
char				*get_next_line(int fd);
int					ft_sizelst(t_gnl **list_of_char, char c);
int					ft_read_error(t_gnl **main_list, char *current);
void				ft_start_gnl(t_gnl **caracter, char c);
void				ft_wipe_list(t_gnl **list_of_char, int counter);
int					ft_read_the_file(int fd, t_gnl **main_list);
int					ft_split_char(const char *c, t_gnl **main_list);
void				ft_add_caracter(t_gnl **main_list, char character);
void				ft_extract_line(t_gnl **list_of_char, char **line,
						int counter);

// FUNCTIONS PRINTF LIBFT
int					ft_printf(const char *string, ...);
int					tratament_flags_advanced(char chr, int *index);
int					tratament_flags(char chr, va_list args, int flag);
int					flag_c(va_list args);
int					flag_percent(void);
int					flag_s(va_list args);
int					flag_di(va_list args, int flag);
int					flag_u(va_list args, int flag);
int					flag_x(va_list args, int flag);
int					flag_x2(va_list args, int flag);
int					flag_p(va_list args);
int					flag_space(void);

#endif
