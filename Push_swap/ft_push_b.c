/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 21:55:00 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/10 19:28:28 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b(t_stack **stc_a, t_stack **stc_b)
{
	t_stack	*curs_a;
	t_stack	*curs_b;

	if (*stc_a == NULL)
		return ;
	curs_b = *stc_b;
	curs_a = *stc_a;
	*stc_a = (*stc_a)->next;
	if (*stc_a != NULL)
		(*stc_a)->prev = NULL;
	curs_a->next = curs_b;
	if (curs_b != NULL)
		curs_b->prev = curs_a;
	*stc_b = curs_a;
}
