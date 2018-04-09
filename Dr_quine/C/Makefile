# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mimazouz <mickaelmazouz@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/19 19:21:07 by mimazouz          #+#    #+#              #
#    Updated: 2018/01/21 17:26:07 by mimazouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	Colleen.c			\
						Grace.c				\
						Sully.c

COLLEEN = Colleen
GRACE = Grace
SULLY = Sully

FLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

OBJECTS = $(SRC_NAME:.c=.o)

all: $(COLLEEN) $(GRACE) $(SULLY)

$(COLLEEN) $(GRACE) $(SULLY): $(OBJECTS)
	gcc $(FLAGS) Grace.o -o $(GRACE)
	gcc $(FLAGS) Sully.o -o $(SULLY)
	gcc $(FLAGS) Colleen.o -o $(COLLEEN)

%.o: %.c
	gcc $(FLAGS) -c $<

clean :
	rm -f $(OBJECTS)

fclean: clean
	rm -f Grace_kid.*
	rm -f $(SULLY)_*
	rm -f $(COLLEEN)
	rm -f $(GRACE)
	rm -f $(SULLY)

re: fclean all
