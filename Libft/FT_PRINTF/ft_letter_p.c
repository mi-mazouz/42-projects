/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:53:11 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:19:26 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_result_letter_p_2(t_printf *link, unsigned long p, int i, int j)
{
	if (link->moins == 0 && link->width > 0)
	{
		while (j != link->width - i && link->width > i)
		{
			ft_putchar(' ');
			j++;
		}
		ft_putstr("0x");
		ft_putnbr_base_unsigned_long(p, 16);
		g_octet = g_octet + i + j;
		return (1);
	}
	else if (link->moins > 0 && link->width > 0)
	{
		ft_putstr("0x");
		ft_putnbr_base_unsigned_long(p, 16);
		while (j != link->width - i && link->width > i)
		{
			ft_putchar(' ');
			j++;
		}
		g_octet = g_octet + i + j;
		return (1);
	}
	return (0);
}

int			ft_result_letter_p(t_printf *link, va_list ap)
{
	unsigned long	p;
	int				j;
	int				i;

	j = 0;
	p = (unsigned long)va_arg(ap, void *);
	i = ft_strlen(ft_itoa_bul(p, 16)) + 2;
	if ((link->moins >= 0 && link->width == 0))
	{
		g_octet = g_octet + ft_strlen(ft_itoa_bul(p, 16)) + 2;
		ft_putstr("0x");
		ft_putnbr_base_unsigned_long(p, 16);
		return (1);
	}
	else if (ft_result_letter_p_2(link, p, i, j) == 1)
		return (1);
	return (0);
}
