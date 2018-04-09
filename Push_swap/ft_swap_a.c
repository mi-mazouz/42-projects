/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:39:01 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/10 19:57:26 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack **stc_a)
{
	int	tmp;

	if (*stc_a == NULL || (*stc_a)->next == NULL)
		return ;
	tmp = (*stc_a)->number;
	(*stc_a)->number = (*stc_a)->next->number;
	(*stc_a)->next->number = tmp;
}
