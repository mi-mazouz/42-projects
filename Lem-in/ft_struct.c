/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:31:47 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/20 17:32:33 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_init_struct(t_lemin *lemin)
{
	lemin->file.start = NULL;
	lemin->file.curs = NULL;
	lemin->pipe.curs = NULL;
	lemin->pipe.start = NULL;
	lemin->pipe.s_tab = NULL;
	lemin->pipe.e_tab = NULL;
	lemin->pipe.link = NULL;
	lemin->pipe.occu = NULL;
	lemin->room.start = NULL;
	lemin->room.curs = NULL;
	lemin->room.end = NULL;
	lemin->ant = -1;
	lemin->c = 0;
	lemin->h = 0;
	lemin->n = 0;
	lemin->p = 0;
	lemin->pipe.pipe = 0;
	lemin->room.room = 0;
}
