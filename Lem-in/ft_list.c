/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:51:47 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/15 18:37:50 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_list_add_tab(t_list **start, char **tab)
{
	if (*start == NULL)
		*start = ft_list_add_new(ft_new_link_tab(tab));
	else
		ft_list_add_last(*start, ft_new_link_tab(tab));
}

void	ft_list_add_name(t_list **start, t_list **curs, char *line)
{
	if (*start == NULL)
	{
		*start = ft_list_add_new(ft_new_link_name(line));
		*curs = *start;
	}
	else
	{
		ft_list_add_last(*curs, ft_new_link_name(line));
		ft_go_to_last(curs);
	}
}

void	ft_list_add_room(t_list **curs, char *line)
{
	if (*curs == NULL)
		*curs = ft_list_add_new(ft_new_link_name(line));
	else
	{
		ft_list_add_last(*curs, ft_new_link_name(line));
		ft_go_to_last(curs);
	}
}
