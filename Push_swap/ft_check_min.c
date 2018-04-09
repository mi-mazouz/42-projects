/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:30:12 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/10 19:54:42 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_min(t_stc *stc, t_stack **curs_a)
{
	while (*curs_a != NULL)
	{
		if ((*curs_a)->number < stc->save->number)
			stc->save = *curs_a;
		*curs_a = (*curs_a)->next;
	}
	*curs_a = stc->pa;
}
