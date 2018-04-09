/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initilise_cmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 16:25:55 by MrRobot           #+#    #+#             */
/*   Updated: 2016/02/24 15:53:25 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_initialise_cmp(t_flags *flags)
{
	if (flags->f > 0)
		flags->cmp = ft_cmp_f;
	else if (flags->r > 0 && flags->t == 0)
		flags->cmp = ft_cmp_reverse;
	else if (flags->t > 0 && flags->r == 0)
		flags->cmp = ft_cmp_time;
	else if (flags->t > 0 && flags->r > 0)
		flags->cmp = ft_cmp_time_and_reverse;
	else
		flags->cmp = ft_cmp_alpha;
}
