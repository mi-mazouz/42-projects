# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mimazouz <mickaelmazouz@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 14:44:34 by mimazouz          #+#    #+#              #
#    Updated: 2018/02/27 14:44:35 by mimazouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	Colleen.s	\
						Grace.s		\
						Sully.s

COLLEEN = Colleen
GRACE = Grace
SULLY = Sully

FLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

OBJECTS = $(SRC_NAME:.s=.o)

all: $(COLLEEN) $(GRACE) $(SULLY)

$(COLLEEN) $(GRACE) $(SULLY): $(OBJECTS)
	gcc $(FLAGS) Colleen.o -o $(COLLEEN)
	gcc $(FLAGS) Grace.o -o $(GRACE)
	gcc $(FLAGS) Sully.o -o $(SULLY)

%.o: %.s
	nasm -f macho64 $<

clean :
	rm -f $(OBJECTS)

fclean: clean
	rm -f Grace_kid.*
	rm -f Sully_*
	rm -f $(COLLEEN)
	rm -f $(GRACE)
	rm -f $(SULLY)

re: fclean all
