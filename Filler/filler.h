/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:57:43 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/26 12:35:48 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <libft.h>

typedef struct		s_board
{
	char			**tab;
	char			**dif;
	int				y;
	int				x;
}					t_board;

typedef struct		s_piece
{
	char			**tab;
	int				y;
	int				x;
}					t_piece;

typedef struct		s_pos
{
	int				*pos;
	int				dif;
}					t_pos;

typedef struct		s_players
{
	char			me;
	char			enemy;
	int				*rush;
	t_list			*pos_me;
	t_list			*pos_enemy;
}					t_players;

typedef struct		s_filler
{
	t_board			board;
	t_piece			piece;
	t_players		players;
	int				put_y;
	int				put_x;
	int				rush;
}					t_filler;

t_pos				*ft_new_link(int i, int j);

t_list				*ft_get_all_pos(char **tab, char letter);
t_list				*ft_get_pos_dif(char **tab, char **dif, char letter);

int					ft_read_shape_bottom_right(t_filler *filler, int *pos);
int					ft_read_shape_bottom_left(t_filler *filler, int *pos);
int					ft_read_shape_top_left(t_filler *filler, int *pos);
int					ft_read_shape_top_right(t_filler *filler, int *pos);
int					ft_choose_read(t_filler *filler, int *pos, int *close);
int					*ft_get_close_pos(t_list **pos_me, t_list *pos_enemy);
int					ft_move_for_check(t_filler *filler, int i, int j, int *pos);
int					ft_check_put(t_filler *filler, int i, int j, int *pos);
int					ft_rush(t_filler *filler, t_board *board, t_players *play);
int					*ft_get_rush_pos(char **tab, char letter);

void				ft_back_track(t_filler *filler);
void				ft_free_data(void *data);
void				ft_sort_list(t_list **pos_me, t_list *ptr);
void				ft_calculate_dif(t_list **pos_me, int *compare);
void				ft_algo(t_filler *filler, char **board, char **dif);
void				ft_get_board(t_board *board, char **split);
void				ft_get_piece(t_piece *piece, char **split);
void				ft_get_player(t_filler *filler);
void				ft_initialize_structure(t_filler *filler);
void				ft_reset_structure(t_filler *filler);

#endif
