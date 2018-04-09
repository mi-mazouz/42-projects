/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 19:54:31 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/10 19:28:20 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_stack **stc_a, t_stack **stc_b)
{
	t_stack	*curs_a;
	t_stack *curs_b;

	if (*stc_b == NULL)
		return ;
	curs_b = *stc_b;
	curs_a = *stc_a;
	*stc_b = (*stc_b)->next;
	if (*stc_b != NULL)
		(*stc_b)->prev = NULL;
	curs_b->next = curs_a;
	if (curs_a != NULL)
		curs_a->prev = curs_b;
	*stc_a = curs_b;
}
