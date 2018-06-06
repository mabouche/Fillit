# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arfohrer <arfohrer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/07 16:22:34 by arfohrer          #+#    #+#              #
#    Updated: 2018/05/15 14:23:55 by arfohrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	ft_check_error.c \
			ft_error.c \
			ft_usage.c \
			create_grid.c \
			fill_grid.c \
			get_information.c \
			piece_top_left.c \
			ft_supp.c \

OBJ = $(SRC_NAME:.c=.o)

INC = -I ./libft/

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INC) 

LIBFT_PATH = ./libft/
NAME = fillit

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ) fillit.h
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ) -L $(LIBFT_PATH) -lft -o $(NAME)

clean:
	rm -fv $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean:
	rm -fv $(OBJ)
	rm	-fv	$(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all
