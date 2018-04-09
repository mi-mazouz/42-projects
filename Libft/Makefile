# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mimazouz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 11:05:34 by mimazouz          #+#    #+#              #
#    Updated: 2017/01/25 15:20:44 by MrRobot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c ./ ./FT_PRINTF

SRC_NAME =	ft_list_size.c										\
			ft_intnew.c											\
			ft_tabdup.c											\
			ft_list_go_to.c										\
			ft_tabjoin.c										\
			ft_list_del.c										\
			ft_list_add.c										\
			ft_putnchar.c										\
			ft_tabstr.c											\
			ft_strtab.c											\
			ft_tabnew.c											\
			ft_tab_add.c										\
			ft_putnchar_fd.c									\
			ft_atoi.c											\
			ft_strclr.c											\
			ft_putnbr_bl.c										\
			ft_putnbr_bul.c										\
			ft_count_words.c									\
			ft_tablen.c											\
			ft_isalnum.c										\
			ft_isalpha.c										\
			ft_strchri.c										\
			ft_get_next_line.c									\
			ft_isascii.c										\
			ft_free_tab.c										\
			ft_power.c											\
			ft_isspace.c										\
			ft_replace_char.c									\
			ft_count_cbl.c										\
			ft_count_cbul.c										\
			ft_isdigit.c										\
			ft_isprint.c										\
			ft_itoa_bl.c										\
			ft_itoa_bul.c										\
			ft_putchar.c										\
			ft_putchar_fd.c										\
			ft_putendl.c										\
			ft_putendl_fd.c										\
			ft_putnbr_fd.c										\
			ft_putstr.c											\
			ft_putstr_fd.c										\
			ft_puttab.c											\
			ft_puttab_fd.c										\
			ft_strcmp.c											\
			ft_strncmp.c										\
			ft_strdel.c											\
			ft_strdup.c											\
			ft_strjoin.c										\
			ft_strlen.c											\
			ft_strnew.c											\
			ft_strsplit.c										\
			ft_str_add.c										\
			ft_strsub.c											\
			ft_tolower.c										\
			ft_toupper.c										\
			ft_printf.c											\
			ft_check_block.c									\
			ft_check_block_2.c									\
			ft_check_block_3.c									\
			ft_check_char_all.c									\
			ft_conv_wchar.c										\
			ft_conv_wchar_2.c									\
			ft_letter_b.c										\
			ft_letter_b_2.c										\
			ft_letter_b_3.c										\
			ft_letter_c.c										\
			ft_letter_d_and_i.c									\
			ft_letter_d_and_i_2.c								\
			ft_letter_d_and_i_3.c								\
			ft_letter_o.c										\
			ft_letter_o_2.c										\
			ft_letter_p.c										\
			ft_letter_percent.c									\
			ft_letter_s.c										\
			ft_letter_s_2.c										\
			ft_letter_s_3.c										\
			ft_letter_u.c										\
			ft_letter_u_2.c										\
			ft_letter_x.c										\
			ft_letter_x_2.c										\
			ft_letter_x_3.c										\
			ft_put_all.c										\
			ft_rest_all_letter.c								\
			ft_rest_all_letter_2.c								\
			ft_return_octet_and_type.c							\
			ft_treatment_block.c								\


NAME = libft.a

FLAGS = -Wall -Werror -Wextra

OBJETS = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJETS)
	ar rc $(NAME) $(OBJETS)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -I./INCLUDES -c $<

clean:
	rm -f $(OBJETS)

fclean: clean
	rm -f $(NAME)

re: fclean all

proper:
	make
	make clean
