/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_in_history.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:53:57 by MrRobot           #+#    #+#             */
/*   Updated: 2016/06/01 08:50:22 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_list	*ft_copy_line(t_list *start)
{
	t_list	*copy;
	t_list	*ptr;
	t_char	*new;

	copy = ft_list_add_new(ft_new_link_line(((t_char *)start->data)->c));
	ptr = start->next;
	while (ptr != NULL)
	{
		new = ft_new_link_line(((t_char *)ptr->data)->c);
		ft_list_add_last(copy, new);
		ptr = ptr->next;
	}
	return (copy);
}

void	ft_list_in_his(t_his *his, t_list *start)
{
	t_list	*new_list;

	new_list = ft_copy_line(start);
	if (his->start == NULL)
	{
		his->start = ft_list_add_new(new_list);
		his->curs = his->start;
	}
	else
	{
		ft_list_add_last(his->start, new_list);
		ft_go_to_last(&his->curs);
	}
}
