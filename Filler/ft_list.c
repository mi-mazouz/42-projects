/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 11:37:19 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/25 18:10:59 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_pos	*ft_new_link(int i, int j)
{
	t_pos *pos;

	pos = (t_pos *)malloc(sizeof(t_pos));
	pos->pos = (int *)malloc(sizeof(int) * 2);
	pos->pos[0] = i;
	pos->pos[1] = j;
	pos->dif = -1;
	return (pos);
}

void	ft_calculate_dif(t_list **pos_me, int *compare)
{
	t_list	*ptr;
	int		dif_y;
	int		dif_x;

	ptr = *pos_me;
	while (ptr != NULL)
	{
		dif_y = ((t_pos *)ptr->data)->pos[0] - compare[0];
		dif_x = ((t_pos *)ptr->data)->pos[1] - compare[1];
		if (dif_y < 0)
			dif_y = -dif_y;
		if (dif_x < 0)
			dif_x = -dif_x;
		((t_pos *)ptr->data)->dif = (dif_y + dif_x);
		ft_sort_list(pos_me, ptr);
		ptr = ptr->next;
	}
}

void	ft_sort_list(t_list **pos_me, t_list *ptr)
{
	t_list	*tmp;
	int		*pos;
	int		tmp_dif;

	tmp = *pos_me;
	while (tmp != NULL)
	{
		if (((t_pos *)tmp->data)->dif > ((t_pos *)ptr->data)->dif)
		{
			tmp_dif = ((t_pos *)tmp->data)->dif;
			pos = ((t_pos *)tmp->data)->pos;
			((t_pos *)tmp->data)->dif = ((t_pos *)ptr->data)->dif;
			((t_pos *)tmp->data)->pos = ((t_pos *)ptr->data)->pos;
			((t_pos *)ptr->data)->dif = tmp_dif;
			((t_pos *)ptr->data)->pos = pos;
			return ;
		}
		tmp = tmp->next;
	}
}
