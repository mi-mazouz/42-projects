# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/26 11:46:03 by fkoehler          #+#    #+#              #
#*   Updated: 2016/12/14 16:50:32 by hponcet          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

vpath %.c ./src ./src/builtins

SRC_NAME =	buffer.c						\
	  		builtins_error.c				\
			builtins_error_2.c				\
			builtins_check.c				\
			bltn_history.c					\
	    	bltn_history_opt.c				\
			bltn_hsearch.c					\
	 		cd.c							\
	  		check_cmd_separators.c			\
	 		check_redir.c					\
	  		cmd_check_input.c				\
	  		cmd_handling.c					\
	 	 	cmd_interpreting.c				\
			cmd_parsing.c					\
			cmd_storage.c					\
			compl.c							\
			compl_display.c					\
			compl_getinfo.c					\
			compl_getpath.c					\
			compl_getpath2.c				\
			compl_key.c						\
	 		compl_str.c						\
		 	cursor.c						\
			echo.c							\
			env.c							\
			env_tools.c						\
			environ.c						\
			exec_bin.c						\
			exit.c							\
			exit_status.c					\
			export.c						\
			fd_handling.c					\
			forking.c						\
			free.c							\
			free_btree.c					\
			ft_cursh.c						\
			ft_cursh_replace.c				\
			ft_cursh_compose.c				\
			ft_glob.c						\
			ft_glob_path_globed.c			\
			ft_glob_compare.c				\
			ft_glob_make.c					\
			ft_glob_path.c					\
			ft_glob_sortchain.c				\
			hash.c							\
			hash_bin.c						\
			hash_new.c						\
			heredoc.c						\
			hist_storage.c					\
			hist_file.c						\
	 		hist_check.c					\
	 		history.c						\
			input_cut_copy.c				\
	 		input_delete_keys.c				\
	 		input_handling.c				\
	 		input_tools.c					\
	  		keys_parsing.c					\
	  		line_moves_1.c					\
	  		line_moves_2.c					\
	  		lst_tools.c						\
	  		lst_tools_2.c					\
	  		main.c							\
	  		main_parsing.c					\
	  		print.c							\
	  		prompt.c						\
	  		putchar.c						\
	  		redirection.c					\
	  		setenv.c						\
	  		signals.c						\
	  		special_char.c					\
	  		str_tools.c						\
	  		str_tools_2.c					\
	  		strsplit_args.c					\
	  		str_subsplit_arg.c				\
	  		term_settings.c					\
	  		unset.c							\
	  		unsetenv.c						\
	  		ft_back_quote.c					\
	  		ft_tools_back_quote.c			\
	  		ft_read.c						\
	  		ft_read_options.c				\
	  		ft_error.c


NAME = 42sh

FLAGS = -Wall -Werror -Wextra

LIB_PATH = libft/

LIB_NAME = libft/libft.a

OBJETS	= $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJETS)
	gcc $(FLAGS) -lcurses $(OBJETS) -L./$(LIB_PATH) -lft -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -I./includes -I./libft/includes -c $<

$(LIB_NAME):
	make proper -C $(LIB_PATH)


clean:
	rm -f $(OBJETS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_NAME)

re: fclean all
