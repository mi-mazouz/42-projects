/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:13:05 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/25 19:20:36 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_initialize_structure(t_filler *filler)
{
	filler->board.tab = NULL;
	filler->board.dif = NULL;
	filler->piece.tab = NULL;
	filler->board.x = -1;
	filler->board.y = -1;
	filler->piece.x = -1;
	filler->piece.y = -1;
	filler->put_y = -1;
	filler->put_x = -1;
	filler->rush = -1;
	filler->players.rush = NULL;
	filler->players.pos_enemy = NULL;
	filler->players.pos_me = NULL;
}

void	ft_reset_structure(t_filler *filler)
{
	if (filler->board.tab != NULL)
		ft_free_tab(filler->board.tab);
	if (filler->piece.tab != NULL)
		ft_free_tab(filler->piece.tab);
	if (filler->players.pos_me != NULL)
		ft_list_del_all(&filler->players.pos_me, &ft_free_data);
	if (filler->players.pos_enemy != NULL)
		ft_list_del_all(&filler->players.pos_enemy, &ft_free_data);
	filler->board.tab = NULL;
	filler->piece.tab = NULL;
	filler->piece.x = -1;
	filler->piece.y = -1;
	filler->put_y = -1;
	filler->put_x = -1;
	filler->board.x = -1;
	filler->board.y = -1;
}
