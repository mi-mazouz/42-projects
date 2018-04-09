/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 22:18:53 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/08 22:25:37 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_list(t_stack **stc_a)
{
	t_stack *ptr;
	t_stack *ptr_2;

	ptr = (*stc_a)->next;
	ptr_2 = *stc_a;
	while (ptr != NULL)
	{
		free(ptr_2);
		ptr_2 = ptr;
		ptr = ptr->next;
	}
}
