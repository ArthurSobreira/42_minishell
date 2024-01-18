NAME = libft.a

SRCS = ft_atol.c ft_bzero.c ft_calloc.c ft_isalnum.c\
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isnonzero_digit.c ft_isprint.c\
		ft_itoa_base.c ft_itoa.c ft_itoa_unsigned.c ft_lstadd_back_bonus.c\
		ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c\
		ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c\
		ft_lstsize_bonus.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c\
		ft_memset.c ft_nbrlen_base.c ft_nbrlen.c ft_putchar.c\
		ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr_base.c ft_putnbr.c\
		ft_putnbr_fd.c ft_putptr.c ft_putstr.c ft_putstr_fd.c ft_split.c\
		ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnew.c\
		ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strtrim.c ft_substr.c\
		ft_tolower.c ft_toupper.c get_next_line.c\
		get_next_line_utils.c ft_sqrt.c ft_pow.c ft_matrixlen.c ft_matrixdel.c\
		ft_printf.c ft_tratament_flags.c ft_flags.c ft_flags_base.c ft_strisnumber.c\
		ft_strcmp.c

OBJ_PATH = bin/
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O0
RM = rm -rf

GREEN = \033[1;32m
RED = \033[1;31m
CYAN = \033[1;35m
RESET = \033[0m

all: $(OBJ_PATH) $(NAME)


$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "\n$(CYAN)Creating $(NAME)$(RESET)\n\n"

$(OBJS): $(OBJ_PATH)%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN)Compiling $(notdir $(<))$(RESET)\n"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@if [ -d $(OBJ_PATH) ]; then \
		printf "$(RED)Cleaning libft/$(OBJ_PATH)$(RESET)\n"; \
		rm -f $(OBJS) -r $(OBJ_PATH); \
	fi

fclean: clean
	@printf "$(RED)Cleaning $(NAME)$(RESET)\n"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean