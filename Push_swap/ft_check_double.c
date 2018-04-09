/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:35:27 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/13 18:20:25 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_double(t_stc *stc)
{
	t_stack	*ptr;
	t_stack	*curs;
	int		i;

	curs = stc->pa;
	if (curs == NULL)
		return (1);
	while (curs->next != NULL)
	{
		ptr = curs->next;
		i = curs->number;
		while (ptr != NULL)
		{
			if (ptr->number == i)
				return (0);
			ptr = ptr->next;
		}
		curs = curs->next;
	}
	return (1);
}
