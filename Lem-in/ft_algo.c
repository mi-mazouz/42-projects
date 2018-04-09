/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 19:02:00 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/22 15:01:39 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	**ft_treat_algo(t_pipe *pipe, t_room *room)
{
	char	**s_nei;
	char	**e_nei;
	char	**path;
	char	*link;

	if ((link = ft_set_link_start_end(pipe, room)) != NULL)
		path = ft_strsplit(link, '-');
	else
	{
		s_nei = ft_set_neigh(pipe->start, ((t_name *)room->start->data)->name);
		e_nei = ft_set_neigh(pipe->start, ((t_name *)room->end->data)->name);
		if (ft_chr_path(s_nei, e_nei, pipe, room) == 0)
			return (NULL);
		path = ft_just_one_path(pipe, room);
		if (path == NULL && pipe->occu != NULL)
			path = ft_path(pipe, room, pipe->occu, pipe->occu);
		else if (path == NULL)
		{
			s_nei = ft_strsplit(pipe->link, '-');
			path = ft_path(pipe, room, s_nei[1], s_nei[0]);
			ft_free_tab(s_nei);
		}
	}
	return (path);
}

char	**ft_path(t_pipe *pipe, t_room *room, char *s_oc, char *e_oc)
{
	char	**s_path;
	char	**e_path;
	char	**tmp;

	s_path = ft_fill_path_start(pipe, pipe->s_tab, ft_strtab(s_oc));
	tmp = ft_tab_add_last(s_path, s_oc);
	ft_free_tab(s_path);
	s_path = ft_tab_add_first(tmp, ((t_name *)room->start->data)->name);
	ft_free_tab(tmp);
	e_path = ft_fill_path_end(pipe, pipe->e_tab, ft_strtab(e_oc));
	if (pipe->link != NULL)
		e_path = ft_tab_add_first(e_path, e_oc);
	tmp = ft_tab_add_last(e_path, ((t_name *)room->end->data)->name);
	ft_free_tab(e_path);
	e_path = ft_tabjoin(s_path, tmp);
	ft_free_tab(s_path);
	ft_free_tab(tmp);
	return (e_path);
}
