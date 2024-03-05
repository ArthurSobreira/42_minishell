NAME = minishell
LIBFT = libs/libft/libft.a
CFLAGS = -Wall -Wextra -Werror -O3 -g3
RFLAGS = -lreadline -lhistory
TEMP_PATH = ./temp/

# Paths for libraries
LIB_PATH = ./libs/libft
LIB_NAME = libft.a

# Colors Definition 
GREEN = "\033[32;1m"
RED = "\033[31;1m"
CYAN = "\033[36;1;3;208m"
WHITE = "\033[37;1;4m"
COLOR_LIMITER = "\033[0m"

# Paths Definitions
HEADER_PATH = ./includes
BIN_PATH = ./bin/
SOURCES_PATH = ./src/
BUILTINS_PATH = built-in/
DEBUG_PATH = debugger/
EXECUTOR_PATH = executor/
EXIT_PATH = exit/
EXPANSION_PATH = expansion/
INIT_PATH = init/
PARSER_PATH = parser/
LEXER_PATH = lexer/
PROMPT_PATH = prompt/
REDIRECT_PATH = redirect/
SIGNALS_PATH = signals/
TOKENIZER_PATH = tokenizer/
TOOLBOX_PATH = toolbox/

SOURCES = main.c \
	$(BUILTINS_PATH)cd.c \
	$(BUILTINS_PATH)echo.c \
	$(BUILTINS_PATH)env.c \
	$(BUILTINS_PATH)exit.c \
	$(BUILTINS_PATH)export.c \
	$(BUILTINS_PATH)pwd.c \
	$(BUILTINS_PATH)unset.c \
	$(DEBUG_PATH)print_coisas.c \
	$(EXECUTOR_PATH)command_table_utils.c \
	$(EXECUTOR_PATH)command_table.c \
	$(EXECUTOR_PATH)command_utils.c \
	$(EXECUTOR_PATH)executor_utils.c \
	$(EXECUTOR_PATH)executor.c \
	$(EXECUTOR_PATH)multiple_commands.c \
	$(EXECUTOR_PATH)redirect_utils.c \
	$(EXIT_PATH)clear_redir.c \
	$(EXIT_PATH)clear.c \
	$(EXIT_PATH)error.c \
	$(EXIT_PATH)garbage.c \
	$(EXPANSION_PATH)expand_variables.c \
	$(EXPANSION_PATH)look_for_variable.c \
	$(INIT_PATH)init_env.c \
	$(INIT_PATH)init_structs.c \
	$(INIT_PATH)init_stuff.c \
	$(LEXER_PATH)error_msg.c \
	$(LEXER_PATH)errors.c \
	$(LEXER_PATH)input_check.c \
	$(LEXER_PATH)input_handling.c \
	$(LEXER_PATH)split_input.c \
	$(LEXER_PATH)tokenizer.c \
	$(PROMPT_PATH)prompt_utils.c \
	$(PROMPT_PATH)prompt.c \
	$(REDIRECT_PATH)here_doc.c \
	$(REDIRECT_PATH)redirect_utils.c \
	$(REDIRECT_PATH)redirect.c \
	$(REDIRECT_PATH)validate_files.c \
	$(REDIRECT_PATH)validate_utils.c \
	$(SIGNALS_PATH)signals.c \
	$(TOOLBOX_PATH)ft_printf_fd.c \
	$(TOOLBOX_PATH)ft_putnbr_base_fd.c \
	$(TOOLBOX_PATH)ft_putptr_fd.c \
	$(TOOLBOX_PATH)export_utils.c \
	$(TOOLBOX_PATH)export_utils2.c \

OBJECTS = $(addprefix $(BIN_PATH), $(SOURCES:%.c=%.o))

all: libft $(BIN_PATH) $(NAME)

libft:
ifeq ($(wildcard $(LIB_PATH)/$(LIB_NAME)),)
	@make -C $(LIB_PATH) --no-print-directory
	@make get_next_line -C $(LIB_PATH) --no-print-directory
	@make ft_printf -C $(LIB_PATH) --no-print-directory
	@echo $(CYAN)" --------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"|  LIBFT  Was Compiled Successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------"$(COLOR_LIMITER)
	@echo " "
endif

$(BIN_PATH)%.o: $(SOURCES_PATH)%.c
	@echo $(GREEN)[Compiling]$(COLOR_LIMITER) $(WHITE)$(notdir $(<))...$(COLOR_LIMITER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_PATH)
	@echo " "

$(NAME): $(OBJECTS)
	@echo $(CYAN)" --------------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"| MINISHELL executable was created successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------------------"$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(RFLAGS) -L $(LIB_PATH) -lft
	@echo " "

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)
	@mkdir -p $(BIN_PATH)$(BUILTINS_PATH)
	@mkdir -p $(BIN_PATH)$(DEBUG_PATH)
	@mkdir -p $(BIN_PATH)$(EXECUTOR_PATH)
	@mkdir -p $(BIN_PATH)$(EXIT_PATH)
	@mkdir -p $(BIN_PATH)$(EXPANSION_PATH)
	@mkdir -p $(BIN_PATH)$(INIT_PATH)
	@mkdir -p $(BIN_PATH)$(LEXER_PATH)
	@mkdir -p $(BIN_PATH)$(PARSER_PATH)
	@mkdir -p $(BIN_PATH)$(PROMPT_PATH)
	@mkdir -p $(BIN_PATH)$(REDIRECT_PATH)
	@mkdir -p $(BIN_PATH)$(SIGNALS_PATH)
	@mkdir -p $(BIN_PATH)$(TOKENIZER_PATH)
	@mkdir -p $(BIN_PATH)$(TOOLBOX_PATH)

clean:
	@echo $(RED)[Removing Objects]$(COLOR_LIMITER)
	@make clean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(BIN_PATH)

fclean: clean
	@echo $(RED)[Removing $(NAME) executable]$(COLOR_LIMITER)
	@echo $(RED)[Removing $(TEMP_PATH)]$(COLOR_LIMITER)
	@make fclean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(NAME)
	@rm -rf $(TEMP_PATH)

re: fclean
	@make --no-print-directory

make_temp:
	@mkdir -p $(TEMP_PATH)

valgrind: make_temp all
	@valgrind -s -q --leak-check=full \
	--show-reachable=yes \
	--show-leak-kinds=all \
	--track-origins=yes \
	--track-fds=yes \
	--suppressions=./suppresion.supp \
	--log-file=$(TEMP_PATH)valgrind.log ./$(NAME)

.PHONY: all clean fclean re libft make_temp valgrind
