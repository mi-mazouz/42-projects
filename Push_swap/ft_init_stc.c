/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 09:07:01 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/10 19:52:36 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stc(t_stc *stc, t_stack **curs_a, t_stack **curs_b)
{
	*curs_a = NULL;
	*curs_b = NULL;
	stc->pa = NULL;
	stc->pb = NULL;
	stc->nb_op = 0;
}
