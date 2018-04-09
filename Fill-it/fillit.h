/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:45:59 by mimazouz          #+#    #+#             */
/*   Updated: 2016/11/29 13:02:20 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./Library/libft.h"
# include <fcntl.h>

typedef struct	s_tetri
{
	char		array[4][5];
	char		letter;
	int			width;
	int			height;
}				t_tetri;

t_tetri			**ft_copy_tetris(int fd, int nb_tetri);
t_tetri			*ft_init_tetri(char *buf, char letter);

void			ft_print_square(char **square);
void			ft_fill_array(char *buf, t_tetri *tetri, char letter);
void			ft_put_blocks_up(t_tetri *tetri);
void			ft_put_blocks_left(t_tetri *tetri);
void			ft_set_tetri_height(t_tetri *tetri);
void			ft_set_tetri_width(t_tetri *tetri);
void			ft_delete_tetri(int i, int j, char **square, t_tetri *tetri);
void			ft_place_tetri(int i, int j, char **square, t_tetri *tetri);

char			**ft_resolve_fillit(t_tetri **array, int nb_tetri);
char			**ft_init_square(int size);

int				ft_error(int fd);
int				ft_check_place(int i, int j, char **square, t_tetri *tetri);
int				search_char_column_n(t_tetri *tetri, char c, int n);
int				ft_read_tetri(int fd);
int				ft_check_file(char *str);
int				ft_check_tetri(char *str, char c);
int				ft_fill_square(char **square, t_tetri **array, int size, int n);

#endif
