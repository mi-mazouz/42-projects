# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/13 15:17:36 by MrRobot           #+#    #+#              #
#    Updated: 2016/11/29 15:20:28 by MrRobot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_algo_sort.c		\
		   ft_atoi_l.c			\
		   ft_check_argv.c		\
		   ft_check_double.c	\
		   ft_check_min.c		\
		   ft_check_sort.c		\
		   ft_flags.c			\
		   ft_free_list.c		\
		   ft_init_stc.c		\
		   ft_make_list.c		\
		   ft_norminette.c		\
		   ft_print_stack.c		\
		   ft_push_a.c			\
		   ft_push_b.c			\
		   ft_ra_ok.c			\
		   ft_reverse_rotate_a.c\
		   ft_rotate_a.c		\
		   ft_rra_or_ra.c		\
		   ft_swap_a.c			\
		   main.c

NAME = push_swap

FLAGS = -Wall -Werror -Wextra

LIB_PATH = ../Libft/

LIB_NAME = ../Libft/libft.a

OBJETS = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJETS)
	gcc $(FLAGS) $(OBJETS) -L$(LIB_PATH) -lft -o $(NAME)

$(LIB_NAME):
	make proper -C $(LIB_PATH)

%.o: %.c
	gcc $(FLAGS) -I../Libft/INCLUDES/ -c $<

clean:
	rm -f $(OBJETS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_NAME)

re: fclean all
