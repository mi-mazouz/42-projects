/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:20:56 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/26 12:35:07 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void		ft_algo(t_filler *filler, char **board, char **dif)
{
	int		*pos;
	t_list	*ptr;

	if (filler->rush == -1 && ft_rush(filler,
				&filler->board, &filler->players) == 1)
		return ;
	ft_list_del_all(&filler->players.pos_me, &ft_free_data);
	filler->rush = 1;
	filler->players.pos_me = ft_get_all_pos(board, filler->players.me);
	if (dif == NULL || (filler->players.pos_enemy = ft_get_pos_dif(board,
					dif, filler->players.enemy)) == NULL)
		return (ft_back_track(filler));
	pos = ft_get_close_pos(&filler->players.pos_me, filler->players.pos_enemy);
	ft_calculate_dif(&filler->players.pos_me, pos);
	ptr = filler->players.pos_me;
	while (ptr != NULL)
	{
		if (ft_choose_read(filler, ((t_pos *)ptr->data)->pos, pos) == 1)
			return ;
		ptr = ptr->next;
	}
}

int	ft_rush(t_filler *filler, t_board *board, t_players *players)
{
	if (players->rush == NULL)
		players->rush = ft_get_rush_pos(board->tab, players->enemy);
	players->pos_me = ft_get_all_pos(board->tab, players->me);
	ft_calculate_dif(&players->pos_me, players->rush);
	if (ft_choose_read(filler, ((t_pos *)players->pos_me->data)->pos,
				players->rush) == 1)
		return (1);
	return (0);
}

void		ft_back_track(t_filler *filler)
{
	t_list *ptr;

	ptr = filler->players.pos_me;
	while (ptr != NULL)
	{
		if (ft_read_shape_bottom_right(filler, ((t_pos *)ptr->data)->pos) == 1)
			return ;
		ptr = ptr->next;
	}
	return ;
}




int			ft_move_for_check(t_filler *filler, int i, int j, int *pos)
{
	int k;
	int l;

	k = pos[0];
	l = pos[1];
	while (i >= 0)
	{
		while (j > 0)
		{
			l--;
			j--;
		}
		if (i == 0)
			break ;
		k--;
		i--;
	}
	if ((k < 0 || l < 0) || ft_check_put(filler, k, l, pos) == -1)
		return (-1);
	return (1);
}

int			ft_check_put(t_filler *filler, int k, int l, int *p)
{
	int	tab[4];

	tab[0] = -1;
	tab[2] = k;
	tab[3] = l;
	while (filler->piece.tab[++tab[0]] != NULL)
	{
		tab[1] = -1;
		if (filler->board.tab[k] == NULL)
			return (-1);
		while (filler->piece.tab[tab[0]][++tab[1]] != 0)
		{
			if (filler->board.tab[k][l] == 0)
				return (-1);
			else if (filler->piece.tab[tab[0]][tab[1]] == '*')
				if (filler->board.tab[k][l] != '.' && (p[0] != k || p[1] != l))
					return (-1);
			l++;
		}
		l = tab[3];
		k++;
	}
	filler->put_y = tab[2];
	filler->put_x = tab[3];
	return (1);
}
