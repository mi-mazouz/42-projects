/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norminette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 15:14:11 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/29 15:19:35 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_all(t_stc *stc, t_stack **curs_a, t_stack **curs_b)
{
	while (*curs_b != NULL)
	{
		ft_push_a(curs_a, curs_b);
		if (*curs_b == NULL && stc->c == 0)
			ft_putstr("pa\n");
		else if ((stc->c > 0) && ft_check_sort(*curs_a) == 1 && *curs_b == NULL)
		{
			ft_printf("%spa%s", BLUE, STOP);
			if (stc->p == 0 && stc->a == 0 && stc->b == 0)
				ft_putstr("\n\n");
		}
		else
			ft_putstr("pa ");
		if (stc->p > 0 || stc->a > 0 || stc->b > 0)
			ft_print_stack(stc, *curs_a, *curs_b);
		stc->nb_op++;
	}
	if ((stc->c == 0 && stc->p == 0 && stc->a == 0 && stc->b == 0) &&
			(stc->r > 0 || stc->n > 0))
		ft_putchar('\n');
}

void	ft_push_min(t_stc *stc, t_stack **curs_a, t_stack **curs_b)
{
	ft_push_b(curs_a, curs_b);
	ft_putstr("pb ");
	if (stc->p > 0 || stc->a > 0 || stc->b > 0)
		ft_print_stack(stc, *curs_a, *curs_b);
	stc->nb_op++;
}

void	ft_print_stack_2(t_stc *stc, t_stack *stc_a, t_stack *stc_b)
{
	if (stc->p > 0 || stc->b == 2 || (stc->b == 1 && stc->a == 1))
		ft_putstr("\nPILE B: ");
	else if (stc->p == 1 || stc->b == 1)
		ft_putstr("PILE B: ");
	if (stc->p > 0 || stc->b > 0)
	{
		while (stc_b != NULL)
		{
			ft_putnbr_bl(stc_b->number, 10);
			ft_putchar(' ');
			stc_b = stc_b->next;
		}
	}
	if (stc_b == NULL || stc_a == NULL)
		ft_putchar('\n');
	ft_putchar('\n');
	if (stc->p == 1)
		stc->p = 2;
	if (stc->a == 1)
		stc->a = 2;
	if (stc->b == 1)
		stc->b = 2;
}

void	ft_swap_pa(t_stc *stc, t_stack **curs_a, t_stack *curs_b)
{
	ft_swap_a(curs_a);
	stc->nb_op++;
	if ((stc->c > 0) && ft_check_sort(*curs_a) == 1 && curs_b == NULL)
	{
		ft_printf("%ssa%s", BLUE, STOP);
		if (stc->p == 0 && stc->a == 0 && stc->b == 0)
			ft_putstr("\n\n");
	}
	else
		ft_putstr("sa ");
	if (stc->p > 0 || stc->a > 0 || stc->b > 0)
		ft_print_stack(stc, *curs_a, curs_b);
}

void	ft_rra_or_ra_2(t_stc *stc, t_stack **curs_a, t_stack *curs_b)
{
	ft_reverse_rotate_a(curs_a);
	if ((stc->c > 0) && ft_check_sort(*curs_a) == 1 && curs_b == NULL)
	{
		ft_printf("%srra%s", BLUE, STOP);
		if (stc->p == 0 && stc->a == 0 && stc->b == 0)
			ft_putstr("\n\n");
	}
	else
		ft_putstr("rra ");
	if (stc->p > 0 || stc->a > 0 || stc->b > 0)
		ft_print_stack(stc, *curs_a, curs_b);
}
