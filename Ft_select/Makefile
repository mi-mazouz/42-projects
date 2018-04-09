# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/25 17:47:45 by MrRobot           #+#    #+#              #
#    Updated: 2016/05/09 09:30:08 by MrRobot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_bottom.c			\
		   ft_check_command.c	\
		   ft_delete.c			\
		   ft_error.c			\
		   ft_free.c			\
		   ft_left.c			\
		   ft_list.c			\
		   ft_put.c				\
		   ft_read_key.c		\
		   ft_return.c			\
		   ft_right.c			\
		   ft_select.c			\
		   ft_signal.c			\
		   ft_struct.c			\
		   ft_term.c			\
		   ft_top.c				\
		   main.c

FLAGS = -Wall -Werror -Wextra

NAME = ft_select

LIB_PATH = ../Libft/

LIB_NAME = ../Libft/libft.a

OBJETS = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJETS)
	gcc $(FLAGS) -lcurses $(OBJETS) -L./$(LIB_PATH) -lft -o $(NAME)

$(LIB_NAME):
	make proper -C $(LIB_PATH)

%.o: %.c
	gcc $(FLAGS) -I../Libft/INCLUDES -c $<

clean:
	rm -f $(OBJETS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_NAME)

re: fclean all
