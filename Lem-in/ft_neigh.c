/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neigh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 19:33:22 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/19 17:41:10 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	**ft_set_neigh_many_room(char **neigh, t_list *start)
{
	int		i;
	int		j;
	char	**new;
	char	**tmp;
	char	**tmp2;

	i = -1;
	new = NULL;
	while (neigh[++i] != NULL)
	{
		j = 0;
		if (new == NULL)
			new = ft_set_neigh(start, neigh[i]);
		else
		{
			tmp = ft_set_neigh(start, neigh[i]);
			while (tmp[j] != NULL)
			{
				tmp2 = ft_tab_add_last(new, tmp[j++]);
				ft_free_tab(new);
				new = tmp2;
			}
		}
	}
	return (new);
}

char	**ft_set_neigh(t_list *start, char *room)
{
	char	**tab;
	char	**tmp;
	char	**lien;

	tab = NULL;
	while (start != NULL)
	{
		lien = ft_strsplit(((t_name *)start->data)->name, '-');
		if (ft_strcmp(lien[0], room) == 0 || ft_strcmp(lien[1], room) == 0)
		{
			if (ft_strcmp(lien[0], room) == 0)
				tmp = ft_tab_add_last(tab, lien[1]);
			else
				tmp = ft_tab_add_last(tab, lien[0]);
			if (tab != NULL)
				ft_free_tab(tab);
			tab = tmp;
		}
		start = start->next;
		ft_free_tab(lien);
	}
	return (tab);
}

char	*ft_set_link(char **s_neigh, char **e_neigh, t_pipe *pipe)
{
	char	**tmp;
	char	*tmp_1;
	char	*str;
	int		i;

	i = 0;
	while (s_neigh[i] != NULL)
	{
		if ((tmp = ft_set_neigh(pipe->start, s_neigh[i])) == NULL)
			return (NULL);
		if ((str = ft_set_common(tmp, e_neigh)) != NULL)
		{
			ft_free_tab(tmp);
			tmp_1 = ft_strjoin(str, "-");
			free(str);
			str = ft_strjoin(tmp_1, s_neigh[i]);
			free(tmp_1);
			return (str);
		}
		i++;
	}
	return (NULL);
}

char	*ft_set_common(char **s_neigh, char **e_neigh)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (e_neigh[j] != NULL)
	{
		if (ft_strcmp(s_neigh[i], e_neigh[j]) == 0)
			return (ft_strdup(s_neigh[i]));
		if (s_neigh[i + 1] == NULL)
		{
			j++;
			i = 0;
			continue ;
		}
		i++;
	}
	return (NULL);
}

char	*ft_set_link_start_end(t_pipe *pipe, t_room *room)
{
	char	*link;
	char	**s_name;
	char	**e_name;

	s_name = ft_strtab(((t_name *)room->start->data)->name);
	e_name = ft_strtab(((t_name *)room->end->data)->name);
	if ((link = ft_set_link(e_name, s_name, pipe)) == NULL)
	{
		ft_free_tab(s_name);
		ft_free_tab(e_name);
		return (NULL);
	}
	ft_free_tab(s_name);
	ft_free_tab(e_name);
	return (link);
}
