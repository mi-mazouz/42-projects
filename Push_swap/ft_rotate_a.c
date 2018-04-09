/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 22:03:35 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/08 20:51:47 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stack **stc_a)
{
	t_stack	*curs;
	t_stack	*ptr;

	if (*stc_a == NULL || (*stc_a)->next == NULL)
		return ;
	curs = *stc_a;
	*stc_a = (*stc_a)->next;
	ptr = *stc_a;
	if (*stc_a != NULL)
		(*stc_a)->prev = NULL;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = curs;
	curs->next = NULL;
	curs->prev = ptr;
}
