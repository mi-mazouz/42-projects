/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_in_stock.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:11:27 by MrRobot           #+#    #+#             */
/*   Updated: 2016/07/14 14:13:40 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	ft_copy_in_stock(t_copy *copy, char c)
{
	if (copy->start == NULL)
	{
		copy->start = ft_list_add_new(ft_new_link_line(c));
		copy->curs = copy->start;
	}
	else
		ft_list_add_last(copy->start, ft_new_link_line(c));
}

void		ft_copy_select(t_line *line)
{
	t_list *ptr;

	ptr = line->start;
	if (line->start == NULL)
		return ;
	if (line->copy.start != NULL)
	{
		ft_list_del_all(&line->copy.start, ft_free);
		line->copy.curs = NULL;
	}
	while (ptr != NULL)
	{
		if (((t_char *)ptr->data)->under == 1)
			ft_copy_in_stock(&line->copy, ((t_char *)ptr->data)->c);
		ptr = ptr->next;
	}
}
