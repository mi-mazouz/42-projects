/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 11:08:32 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/22 15:45:41 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_chr_path(char **s_n, char **e_n, t_pipe *pipe, t_room *room)
{
	char	**s_tmp;
	char	**e_tmp;

	if (s_n == NULL || e_n == NULL)
		return (0);
	if ((pipe->occu = ft_set_common(s_n, e_n)) != NULL)
		return (1);
	else if ((pipe->link = ft_set_link(s_n, e_n, pipe)) != NULL)
		return (1);
	else
	{
		ft_list_add_tab(&pipe->s_tab, s_n);
		ft_list_add_tab(&pipe->e_tab, e_n);
		s_tmp = ft_set_neigh_many_room(s_n, pipe->start);
		e_tmp = ft_set_neigh_many_room(e_n, pipe->start);
		s_tmp = ft_remove_tab(s_n, s_tmp, ((t_name *)room->start->data)->name);
		e_tmp = ft_remove_tab(e_n, e_tmp, ((t_name *)room->end->data)->name);
		s_n = s_tmp;
		e_n = e_tmp;
		return (ft_chr_path(s_n, e_n, pipe, room));
	}
}

char	**ft_fill_path_end(t_pipe *pipe, t_list *tab, char **occu)
{
	char	**tmp;
	char	**tmp3;
	char	*tmp2;
	char	**path;

	path = NULL;
	ft_go_to_last(&tab);
	while (tab != NULL)
	{
		if (path == NULL)
			tmp2 = ft_set_link(((t_tab *)tab->data)->tab, occu, pipe);
		else
			tmp2 = ft_set_link(((t_tab *)tab->data)->tab, path, pipe);
		tmp3 = ft_strsplit(tmp2, '-');
		if (path == NULL)
			path = ft_strtab(tmp3[1]);
		else
		{
			tmp = ft_tab_add_last(path, tmp3[1]);
			path = tmp;
		}
		tab = tab->prev;
	}
	ft_free_tab(occu);
	return (path);
}

char	**ft_just_one_path(t_pipe *pipe, t_room *room)
{
	char	**path;
	char	**tmp;
	char	*save;

	if (pipe->s_tab == NULL && pipe->e_tab == NULL)
	{
		if (pipe->occu != NULL)
			path = ft_strtab(pipe->occu);
		else
		{
			path = ft_strsplit(pipe->link, '-');
			tmp = ft_strtab(path[1]);
			save = ft_strdup(path[0]);
			ft_free_tab(path);
			path = ft_tab_add_last(tmp, save);
			ft_free_tab(tmp);
			free(save);
		}
		tmp = ft_tab_add_first(path, ((t_name *)room->start->data)->name);
		ft_free_tab(path);
		path = ft_tab_add_last(tmp, ((t_name *)room->end->data)->name);
		ft_free_tab(tmp);
		return (path);
	}
	return (NULL);
}

int		ft_room_exist(char *room, t_list *start)
{
	t_list	*curs;

	curs = start;
	ft_go_to_first(&curs);
	while (curs != NULL)
	{
		if (ft_strcmp(room, ((t_name *)curs->data)->name) == 0)
			return (1);
		curs = curs->next;
	}
	return (0);
}

char	**ft_fill_path_start(t_pipe *pipe, t_list *tab, char **occu)
{
	char	**tmp;
	char	**tmp3;
	char	*tmp2;
	char	**path;

	path = NULL;
	ft_go_to_last(&tab);
	while (tab != NULL)
	{
		if (path == NULL)
			tmp2 = ft_set_link(((t_tab *)tab->data)->tab, occu, pipe);
		else
			tmp2 = ft_set_link(((t_tab *)tab->data)->tab, path, pipe);
		tmp3 = ft_strsplit(tmp2, '-');
		if (path == NULL)
			path = ft_strtab(tmp3[1]);
		else
		{
			tmp = ft_tab_add_first(path, tmp3[1]);
			path = tmp;
		}
		tab = tab->prev;
	}
	ft_free_tab(occu);
	return (path);
}
