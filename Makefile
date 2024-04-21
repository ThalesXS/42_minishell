#	====================		Directories		====================

INC = includes

SRC = srcs
OBJ_DIR = objects

#	====================		Files      		====================

NAME = minishell
FILES = main.c minishell.c parser.c executer.c envs.c api.c \
	signals/signal.c signals/signal_handlers.c builtins/builtins.c \
	builtins/echo.c builtins/cd.c builtins/pwd.c builtins/export.c \
	builtins/unset.c builtins/env.c builtins/exit.c execve.c \
	parse_utils.c directory.c split_token.c expander.c treat_token.c \
	pipe.c redirect.c free.c expander_utils.c redirect_utils.c \
	pipe_utils.c envs_utils.c builtins/cd_utils.c
OBJ = $(FILES:.c=.o)
TARGET = $(addprefix $(OBJ_DIR)/, $(OBJ))

#	====================		Commands   		====================

CC = cc
RM = rm

#	====================		Flags      		====================

W = -Wall -Wextra -Werror
O = -c
I = -I $(INC)
WBLOCK = --no-print-directory

LIBFT = -L ./libft -lft
READLINE = -lreadline

#	====================		Colors     		====================

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[0;33m
RESET = \033[0m

#	====================		Rules      		====================

all: $(NAME)

$(NAME): $(OBJ_DIR) $(TARGET)
	@make $(WBLOCK) -C ./libft
	@$(CC) $(W) $(TARGET) $(LIBFT) $(READLINE) -o $(NAME)
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC)/%.c
	@$(CC) $(W) $(I) $(O) $< -o $@
	@echo "$(GREEN)$(NAME) object files created$(RESET)"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@mkdir $(OBJ_DIR)/signals
	@mkdir $(OBJ_DIR)/builtins

clean:
	@make $(WBLOCK) clean -C ./libft
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(RED)$(OBJ_DIR) deleted$(RESET)"

fclean: clean
	@make $(WBLOCK) fclean -C ./libft
	@$(RM) -rf $(NAME)
	@echo "$(RED)$(NAME) deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus

norm:
	norminette -R CheckForbiddenSourceHeader headers/*.h srcs/*.c srcs/**/*.c

leak: all
	valgrind --leak-check=full --show-leak-kinds=all \
		--suppressions=readline_leaks ./$(NAME)
		