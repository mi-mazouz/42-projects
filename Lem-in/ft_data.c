/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:42:56 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/15 17:21:29 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_treat_data(t_lemin *lemin)
{
	char	*line;

	line = NULL;
	while (ft_get_next_line(0, &line) == 1)
	{
		if (ft_check_line(lemin, line) == 0)
		{
			ft_strdel(&line);
			return (0);
		}
		if ((line[0] != '#' || line[0] == '#') && line[1] != '#')
			ft_list_add_name(&lemin->file.start, &lemin->file.curs, line);
		ft_strdel(&line);
	}
	return (1);
}

int		ft_set_room(t_room *room, t_pipe *pipe, char *line)
{
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) == 3)
	{
		if (ft_atoi(tab[1]) < 0 || ft_atoi(tab[2]) < 0 || pipe->pipe == 1)
			return (0);
		else if (ft_check_dup(room->curs, tab[0]) == 0)
			return (0);
		ft_list_add_room(&room->curs, tab[0]);
		room->room = 1;
	}
	else
	{
		if (ft_tablen(tab) != 1 || ft_set_pipe(pipe, room, tab[0]) == 0)
		{
			ft_free_tab(tab);
			return (0);
		}
	}
	ft_free_tab(tab);
	return (1);
}

int		ft_set_pipe(t_pipe *pipe, t_room *room, char *line)
{
	char	**tab;

	if (room->end == NULL || room->start == NULL || room->room == 0)
		return (0);
	tab = ft_strsplit(line, '-');
	if (ft_strchri(line, '-') == -1 || ft_tablen(tab) != 2)
	{
		ft_free_tab(tab);
		return (0);
	}
	if (ft_check_dup(pipe->start, line) == 0)
		return (0);
	else if (ft_room_exist(tab[0], room->curs) == 0)
		ft_exit();
	ft_list_add_name(&pipe->start, &pipe->curs, line);
	pipe->pipe = 1;
	ft_free_tab(tab);
	return (1);
}

int		ft_set_start_end(t_file *file, t_room *room, char *line, int t)
{
	char	**tab;

	ft_list_add_name(&file->start, &file->curs, line);
	if ((t == 1 && room->end != NULL) || (t == 0 && room->start != NULL)
			|| line[0] == 'L' || line[0] == '#')
		return (0);
	if (ft_tablen((tab = ft_strsplit(line, ' '))) != 3)
	{
		ft_free_tab(tab);
		return (0);
	}
	if (ft_atoi(tab[1]) < 0 || ft_atoi(tab[2]) < 0)
		return (0);
	ft_list_add_room(&room->curs, tab[0]);
	if (t == 1)
		room->end = room->curs;
	else
		room->start = room->curs;
	ft_free_tab(tab);
	return (1);
}
