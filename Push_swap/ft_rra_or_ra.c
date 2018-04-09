/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_or_ra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 19:24:58 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/29 15:20:02 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra_or_ra(t_stc *stc, t_stack **curs_a, t_stack *curs_b)
{
	if (ft_ra_ok(*curs_a, stc->save->number) == 1)
	{
		ft_rotate_a(curs_a);
		if (stc->c > 0 && ft_check_sort(*curs_a) == 1 && curs_b == NULL)
		{
			ft_printf("%sra%s", BLUE, STOP);
			if ((stc->p == 0 && stc->a == 0 && stc->b == 0) ||
					(stc->r > 0 || stc->n > 0))
				ft_putstr("\n\n");
		}
		else
			ft_putstr("ra ");
		if (stc->p > 0 || stc->a > 0 || stc->b > 0)
			ft_print_stack(stc, *curs_a, curs_b);
	}
	else
		ft_rra_or_ra_2(stc, curs_a, curs_b);
	stc->nb_op++;
}

int		ft_special_k(t_stc *stc, t_stack **curs_a, t_stack *curs_b)
{
	t_stack	*curs;

	curs = stc->pa;
	while (curs->next->next != NULL)
	{
		if (curs->number > curs->next->number)
			return (0);
		curs = curs->next;
	}
	ft_special_k_2(stc, curs, curs_a, curs_b);
	if (stc->p > 0 || stc->a > 0 || stc->b > 0)
		ft_print_stack(stc, *curs_a, curs_b);
	stc->pa = *curs_a;
	if ((stc->c == 0 && stc->p == 0 && stc->a == 0 && stc->b == 0) &&
			(stc->r > 0 || stc->n > 0))
		ft_putchar('\n');
	return (1);
}

void	ft_special_k_2(t_stc *stc, t_stack *curs, t_stack **curs_a,
		t_stack *curs_b)
{
	if (curs->number > curs->next->number)
	{
		ft_reverse_rotate_a(curs_a);
		ft_putstr("rra ");
		if (stc->p > 0 || stc->a > 0 || stc->b > 0)
			ft_print_stack(stc, *curs_a, curs_b);
		ft_reverse_rotate_a(curs_a);
		ft_putstr("rra ");
		if (stc->p > 0 || stc->a > 0 || stc->b > 0)
			ft_print_stack(stc, *curs_a, curs_b);
		ft_swap_a(curs_a);
		ft_putstr("sa ");
		if (stc->p > 0 || stc->a > 0 || stc->b > 0)
			ft_print_stack(stc, *curs_a, curs_b);
		ft_rotate_a(curs_a);
		ft_putstr("ra ");
		if (stc->p > 0 || stc->a > 0 || stc->b > 0)
			ft_print_stack(stc, *curs_a, curs_b);
		ft_rotate_a(curs_a);
		if (stc->c > 0)
			ft_printf("%sra%s", BLUE, STOP);
		else
			ft_putstr("ra");
		stc->nb_op += 5;
	}
}

void	ft_print_result(t_stc stc)
{
	ft_putstr("Resultat: ");
	while (stc.pa->next != NULL)
	{
		ft_printf("%d ", stc.pa->number);
		stc.pa = stc.pa->next;
	}
	ft_printf("%d\n", stc.pa->number);
}

int		ft_size_stack(t_stack *curs_a)
{
	int i;

	i = 0;
	while (curs_a != NULL)
	{
		i++;
		curs_a = curs_a->next;
	}
	return (i);
}
