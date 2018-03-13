# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alamy <alamy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 18:07:22 by lesanche          #+#    #+#              #
#    Updated: 2018/03/08 17:21:36 by alamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

LIBFT_DIR = libft

MLIBX_DIR = minilibx

SRC = \
				main.c \
				julia.c \
				mandelbrot.c \
				burn_ship.c \
				barnsley.c \
				tricorn.c \
				carpet_serpinski.c \
				color.c \
				keyboard.c \
				write_string.c \
				multi_thread.c \
				mouse.c 

OBJ = $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
MLIBX = $(MLIBX_DIR)/libmlx.a

# PROGRESS BAR
T = $(words $(OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

#Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft -L$(MLIBX_DIR) -lmlx -framework OpenGL -framework AppKit -lm
	@echo "\n$(NAME) compilation : $(_YELLOW)done$(_END)"

%.o:    %.c
	@printf "%-60b\r" "$(ECHO) $(_PURPLE) Compiling $@ $(_END)"
	@$(CC) $(CFLAGS) -c $<

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean : 
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY: all clean fclean re
