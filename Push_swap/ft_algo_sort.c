/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:37:05 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/14 11:33:25 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_sort(t_stc *stc, t_stack *curs_a, t_stack *curs_b)
{
	curs_a = stc->pa;
	curs_b = stc->pb;
	stc->save = stc->pa;
	if (stc->p == 1 || stc->a == 1 || stc->b == 1)
		ft_print_stack(stc, curs_a, curs_b);
	if ((ft_size_stack(curs_a) > 3) && ft_special_k(stc, &curs_a, curs_b) == 1)
		return ;
	while (stc->pa != NULL)
	{
		if (curs_a->next && curs_a->number > curs_a->next->number)
			ft_swap_pa(stc, &curs_a, curs_b);
		ft_check_min(stc, &curs_a);
		while (curs_a->number != stc->save->number)
			ft_rra_or_ra(stc, &curs_a, curs_b);
		if (ft_check_sort(curs_a) == 1)
			break ;
		if (curs_a->next != NULL)
			ft_push_min(stc, &curs_a, &curs_b);
		stc->pa = curs_a;
		stc->save = stc->pa;
		if (stc->pa->next == NULL)
			break ;
	}
	ft_push_all(stc, &curs_a, &curs_b);
	stc->pa = curs_a;
}
