# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/10 08:22:48 by MrRobot           #+#    #+#              #
#    Updated: 2016/11/23 16:05:58 by MrRobot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	ft_21sh.c				\
			ft_aggregations.c		\
			ft_arrow.c				\
			ft_binary_tree.c		\
			ft_cd.c					\
			ft_cmd.c				\
			ft_copy_and_paste.c		\
			ft_copy_in_stock.c		\
			ft_curs_pos.c			\
			ft_delete.c				\
			ft_move_in_line.c		\
			ft_treat_special_char.c	\
			ft_echo.c				\
			ft_env.c				\
			ft_env_list.c			\
			ft_error.c				\
			ft_exec_cmd.c			\
			ft_exit.c				\
			ft_fd.c					\
			ft_free.c				\
			ft_heredoc.c			\
			ft_history.c			\
			ft_insert_char.c		\
			ft_line_list.c			\
			ft_line_parenthesis.c	\
			ft_list_in_history.c	\
			ft_parenthesis.c		\
			ft_path.c				\
			ft_pipe.c				\
			ft_put.c				\
			ft_quote.c				\
			ft_redirect.c			\
			ft_return.c				\
			ft_separator.c			\
			ft_setenv.c				\
			ft_set_file.c			\
			ft_signal.c				\
			ft_strsplit_space.c		\
			ft_struct.c				\
			ft_tabulation.c			\
			ft_term.c				\
			ft_touch.c				\
			ft_unsetenv.c			\
			ft_up_and_down.c		\
			main.c

NAME = 21sh

FLAGS = -Wall -Werror -Wextra -g

LIB_PATH = ../Libft/

LIB_NAME = ../Libft/libft.a

OBJETS = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJETS)
	gcc $(FLAGS) -lcurses $(OBJETS) -L./$(LIB_PATH) -lft -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -I../Libft/INCLUDES -c $<

$(LIB_NAME):
	make proper -C $(LIB_PATH)

clean :
	rm -f $(OBJETS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_NAME)

re: fclean all
