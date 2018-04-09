/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:13:09 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/13 15:31:05 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stc *stc, t_stack *stc_a, t_stack *stc_b)
{
	if (stc->p == 2 || stc->a == 2)
		ft_putstr("\nPILE A: ");
	else if (stc->p == 1 || stc->a == 1)
		ft_putstr("PILE A: ");
	if (stc->p > 0 || stc->a > 0)
	{
		while (stc_a != NULL)
		{
			ft_putnbr_bl(stc_a->number, 10);
			ft_putchar(' ');
			stc_a = stc_a->next;
		}
	}
	ft_print_stack_2(stc, stc_a, stc_b);
}
