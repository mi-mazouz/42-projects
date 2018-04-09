/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 23:22:11 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/08 18:39:37 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_stack **stc_a)
{
	t_stack	*curs;
	t_stack *ptr;

	if (*stc_a == NULL || (*stc_a)->next == NULL)
		return ;
	curs = *stc_a;
	while (curs->next != NULL)
	{
		if (curs->next->next == NULL)
			ptr = curs;
		curs = curs->next;
	}
	curs->prev = NULL;
	curs->next = *stc_a;
	(*stc_a)->prev = curs;
	ptr->next = NULL;
	*stc_a = curs;
}
