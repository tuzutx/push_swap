# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolaeche <nolaeche@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 17:06:03 by nolaeche          #+#    #+#              #
#    Updated: 2026/02/05 18:14:32 by nolaeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

SRCS_DIR = src
INCS_DIR = include
LIBFT_DIR = libft
PRINTF_DIR = printf

LIBFT_CFLAGS = -I$(LIBFT_DIR)

PRINTF_CFLAGS = -I$(PRINTF_DIR)
PROJ_CFLAGS = -I$(INCS_DIR)

PRINTF_LDFLAGS = -L$(PRINTF_DIR) -lftprintf
LIBFT_LDFLAGS = -L$(LIBFT_DIR) -lft


SRCS_FILES = algo.c \
			 algorithm_aux.c \
			 algorithm_ejecution.c \
			 algorithm_motor.c \
			 algorithm_sort3.c \
			 operators.c \
			 main.c \
			 errors.c \
			 clean.c \
			 algorithm_ejecution2.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(SRCS:.c=.o)

all: libft/libft.a printf/libftprintf.a $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_CFLAGS) $(PROJ_CFLAGS) -c $< -o $@

libft/libft.a:
	@make bonus -C libft

printf/libftprintf.a:
	@make -C printf

clean:
	@make clean -C libft
	@make clean -C printf
	rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	@make fclean -C printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
