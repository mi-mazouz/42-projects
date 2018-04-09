/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 15:14:26 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:21:07 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_result_letter_x(t_printf *link, va_list ap)
{
	unsigned long	p;

	link->m = 0;
	link->k = 0;
	p = ft_return_type_u(link, ap);
	link->o = (int)ft_strlen(ft_itoa_bul(p, 16));
	if (link->moins == 0 && link->zero == 0 && link->preci == -1 &&
			link->width > 0)
	{
		ft_result_letter_x_1(link, &p);
		if ((link->point < 2 && p != 0) || link->point == -1)
		{
			if (link->letter == 'X')
				ft_putnbr_bul(p, 16);
			else
				ft_putnbr_base_unsigned_long(p, 16);
			g_octet = g_octet + link->m + link->o;
			return (1);
		}
		g_octet = g_octet + link->m + link->o;
		return (1);
	}
	else
		ft_result_letter_x_2(link, &p);
	return (1);
}

void	ft_result_letter_x_1(t_printf *link, unsigned long *p)
{
	if (*p == 0 && link->point == 1)
		link->m--;
	if (link->htag > 0)
		link->m += 2;
	while (link->m < link->width - link->o && link->width > link->o)
	{
		ft_putchar(' ');
		link->m++;
	}
	if (link->htag > 0)
	{
		if (link->letter == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
	}
}

int		ft_result_letter_x_2(t_printf *link, unsigned long *p)
{
	if (link->moins >= 0 && link->zero >= 0 && link->preci == -1 &&
			link->width == 0)
	{
		ft_result_letter_x_3(link, p);
		if ((link->point < 2 && *p != 0) || link->point == -1)
		{
			if (link->letter == 'X')
				ft_putnbr_bul(*p, 16);
			else
				ft_putnbr_base_unsigned_long(*p, 16);
			g_octet = g_octet + link->m + link->o;
			return (1);
		}
		g_octet = g_octet + link->m;
		return (1);
	}
	else
		ft_result_letter_x_4(link, p);
	return (1);
}

void	ft_result_letter_x_3(t_printf *link, unsigned long *p)
{
	if (link->htag > 0 && *p != 0)
	{
		if (link->letter == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		link->m += 2;
	}
}

int		ft_result_letter_x_4(t_printf *link, unsigned long *p)
{
	if (link->moins == 0 && link->zero >= 0 && link->preci > -1 &&
			link->width > 0)
	{
		ft_result_letter_x_5(link, p);
		if (*p != 0 || (*p == 0 && link->point != 1 && link->preci > 0))
		{
			if (link->letter == 'X')
				ft_putnbr_bul(*p, 16);
			else
				ft_putnbr_base_unsigned_long(*p, 16);
		}
		g_octet = g_octet + link->m + link->o + link->k;
		return (1);
	}
	else
		ft_result_letter_x_6(link, p);
	return (1);
}
