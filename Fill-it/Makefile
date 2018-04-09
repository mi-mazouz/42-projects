# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/16 11:26:39 by mimazouz          #+#    #+#              #
#    Updated: 2016/11/29 12:58:14 by MrRobot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	ft_check_file.c		\
			ft_copy_tetris.c	\
			ft_fill_square.c	\
			ft_put_blocks.c		\
			ft_read_tetris.c	\
			ft_set_tetri.c		\
			ft_small_square.c	\
			main.c

NAME = fillit

FLAGS = -Wall -Werror -Wextra

LIB_PATH = ./Library

LIB_NAME = ./Library/libft.a

OBJETS = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJETS)
	gcc $(FLAGS) $(OBJETS) -L$(LIB_PATH) -lft -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -I../Libft/INCLUDES -c $<

$(LIB_NAME):
	make proper -C $(LIB_PATH)

clean:
	rm -f $(OBJETS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_NAME)

re: fclean all
