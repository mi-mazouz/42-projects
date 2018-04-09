/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest_all_letter_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:07:23 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:22:15 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_result_letter_o_5(t_printf *link, unsigned long *p)
{
	if (link->moins >= 0 && link->zero >= 0 && link->preci > -1 &&
			link->width == 0)
	{
		if (link->htag > 0 && *p != 0)
			link->m++;
		while (link->m < link->preci - link->o)
		{
			ft_putchar('0');
			link->m++;
		}
		if ((*p != 0 && link->preci != 0) || link->htag > 0)
		{
			ft_putnbr_base_unsigned_long(*p, 8);
			g_octet = g_octet + link->m + link->o;
			return (1);
		}
		g_octet = g_octet + link->m;
		return (1);
	}
	else
		ft_result_letter_o_6(link, p);
	return (1);
}
