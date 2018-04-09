# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/14 11:57:16 by MrRobot           #+#    #+#              #
#    Updated: 2016/05/10 08:17:14 by MrRobot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	ft_absolut_path.c		\
			ft_cd.c					\
			ft_check_command.c		\
			ft_env.c				\
			ft_env_and_list.c		\
			ft_error.c				\
			ft_fork.c				\
			ft_free_list.c			\
			ft_return_path.c		\
			ft_setenv.c				\
			ft_unsetenv.c			\
			ft_signal.c				\
			main.c

FLAGS = -Wall -Werror -Wextra

NAME = minishell

LIB_PATH = ../Libft/

LIB_NAME = ../Libft/libft.a

OBJETS = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJETS)
	gcc $(FLAGS) $(OBJETS) -L$(LIB_PATH) -lft -o $(NAME)

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
