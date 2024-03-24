# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:29:26 by pabernar          #+#    #+#              #
#    Updated: 2024/02/26 22:26:40 by txisto-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell 
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O3
RM = rm -rf
LIBFT = libft/libft.a
LIBFT_DIR = libft/
SRCS = main.c minishell.c \
parser.c \
executer.c \
envs.c \
api.c \
signals/signal.c signals/signal_handlers.c \
builtins/builtins.c \
builtins/echo.c \
builtins/cd.c \
builtins/pwd.c \
builtins/export.c \
builtins/unset.c \
builtins/env.c \
builtins/exit.c \
execve.c \
parse_utils.c \
directory.c \
split_token.c \
expander.c \
treat_token.c \
pipe.c \
redirect.c \
free.c
SRCS_DIR = srcs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_DIR = objs/
MINISH = -lreadline

all: $(NAME)

$(NAME): $(OBJS_DIR) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MINISH)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p objs
	mkdir -p objs/signals/
	mkdir -p objs/builtins/
clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader headers/*.h srcs/*.c srcs/**/*.c

leak: all
	valgrind --leak-check=full --show-leak-kinds=all \
		--suppressions=readline_leaks ./$(NAME)
