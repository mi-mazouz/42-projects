# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/09 09:28:25 by MrRobot           #+#    #+#              #
#    Updated: 2016/05/09 09:28:52 by MrRobot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	ft_check_fake_path.c	\
			ft_cmp_all.c			\
			ft_creat_elem.c			\
			ft_error.c				\
			ft_fill_option.c		\
			ft_initialise_cmp.c		\
			ft_initialise_struct.c	\
			ft_make_all.c			\
			ft_one_path.c			\
			ft_print_file.c			\
			ft_print_law.c			\
			ft_print_date.c			\
			ft_print_link.c			\
			ft_read_argv.c			\
			ft_read_dirr.c			\
			ft_recursive.c			\
			ft_treat_path.c			\
			ft_free_lst.c			\
			ft_norminette.c			\
			ft_print_colors.c		\
			ft_print_grp.c			\
			ft_print_mam.c			\
			ft_print_usr.c			\
			main.c

NAME = ft_ls

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
	gcc $(FLAGS) -I../Libft/INCLUDES -c $<

clean:
	rm -f $(OBJETS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_NAME)

re: fclean all
