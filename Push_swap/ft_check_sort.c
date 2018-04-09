/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 22:00:32 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/09 02:46:59 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_sort(t_stack *curs_a)
{
	while (curs_a->next != NULL)
	{
		if (curs_a->number > curs_a->next->number)
			return (0);
		curs_a = curs_a->next;
	}
	return (1);
}
