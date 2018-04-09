SRC_NAME =		ft_link.c			\
				ft_list.c			\
				ft_neigh.c			\
				ft_data.c			\
				ft_check.c			\
				ft_put.c			\
				ft_struct.c			\
				ft_path.c			\
				ft_algo.c			\
				ft_tab.c			\
				ft_exit.c			\
				main.c

NAME = Lem_in

FLAGS = -Wall -Wextra -Werror

LIB_PATH = ../Libft

LIB_NAME = ../Libft/libft.a


OBJETS = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJETS)
	 gcc $(FLAGS) $(OBJETS) -L./$(LIB_PATH) -lft -o $(NAME)

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
