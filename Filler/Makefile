# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 12:42:11 by MrRobot           #+#    #+#              #
#    Updated: 2017/01/26 17:16:55 by MrRobot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	ft_structure.c			\
			ft_datas.c				\
			ft_algo.c				\
			ft_get_pos.c			\
			ft_free.c				\
			ft_read_piece.c			\
			ft_list.c				\
			main.c

NAME = mimazouz.filler

FLAGS = -Wall -Werror -Wextra -g

LIB_PATH = ../Libft/

LIB_NAME = ../Libft/libft.a

OBJECTS = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJECTS)
	gcc $(FLAGS) $(OBJECTS) -fsanitize=address -L./$(LIB_PATH) -lft -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -I./$(LIB_PATH)/INCLUDES -I./ -c $<

$(LIB_NAME):
	make proper -C $(LIB_PATH)

clean :
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_NAME)

re: fclean all
