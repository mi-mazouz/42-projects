/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_ok.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 22:31:06 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/10 16:17:57 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_ra_ok(t_stack *stc_a, int number)
{
	t_stack	*curs_a;
	int		i;
	int		j;

	j = 0;
	i = 0;
	curs_a = stc_a;
	while (stc_a != NULL)
	{
		stc_a = stc_a->next;
		i++;
	}
	i = i / 2;
	while (j <= i)
	{
		if (curs_a->number == number)
			return (1);
		curs_a = curs_a->next;
		j++;
	}
	return (0);
}
