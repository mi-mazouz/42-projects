/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 18:46:31 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:20:36 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_result_letter_u(t_printf *link, va_list ap)
{
	unsigned long	p;

	link->m = 0;
	link->k = 0;
	p = ft_return_type_u(link, ap);
	link->o = (int)ft_strlen(ft_itoa_bul(p, 10));
	if (link->moins == 0 && link->zero == 0 && link->preci == -1 &&
			link->width > 0)
	{
		ft_result_letter_u_1(link, &p);
		if ((link->point < 2 && p != 0) || link->point == -1)
		{
			ft_putnbr_base_unsigned_long(p, 10);
			g_octet = g_octet + link->m + link->o;
			return (1);
		}
		g_octet = g_octet + link->m;
		return (1);
	}
	else
		ft_result_letter_u_2(link, &p);
	return (1);
}

void	ft_result_letter_u_1(t_printf *link, unsigned long *p)
{
	if (*p == 0 && link->point == 1)
		link->m--;
	while (link->m < link->width - link->o && link->width > link->o)
	{
		ft_putchar(' ');
		link->m++;
	}
}

int		ft_result_letter_u_2(t_printf *link, unsigned long *p)
{
	if (link->moins >= 0 && link->zero >= 0 && link->preci == -1 &&
			link->width == 0)
	{
		if ((link->point < 2 && *p != 0) || link->point == -1)
		{
			ft_putnbr_base_unsigned_long(*p, 10);
			g_octet = g_octet + link->m + link->o;
			return (1);
		}
		g_octet = g_octet + link->m;
		return (1);
	}
	else
		ft_result_letter_u_3(link, p);
	return (1);
}

int		ft_result_letter_u_3(t_printf *link, unsigned long *p)
{
	if (link->moins == 0 && link->zero >= 0 && link->preci > -1 &&
			link->width > 0)
	{
		if (*p == 0 && link->preci == 0)
			link->m--;
		while (link->m < link->width - link->o &&
				link->m < link->width - link->preci)
		{
			ft_putchar(' ');
			link->m++;
		}
		while (link->k < link->preci - link->o)
		{
			ft_putchar('0');
			link->k++;
		}
		if (*p != 0 || (*p == 0 && link->point != 1 && link->preci > 0))
			ft_putnbr_base_unsigned_long(*p, 10);
		g_octet = g_octet + link->m + link->o + link->k;
		return (1);
	}
	else
		ft_result_letter_u_4(link, p);
	return (1);
}

int		ft_result_letter_u_4(t_printf *link, unsigned long *p)
{
	if (link->moins >= 0 && link->zero >= 0 && link->preci > -1 &&
			link->width == 0)
	{
		while (link->m < link->preci - link->o)
		{
			ft_putchar('0');
			link->m++;
		}
		if ((link->point < 3 && *p != 0) || link->point == -1)
		{
			ft_putnbr_base_unsigned_long(*p, 10);
			g_octet = g_octet + link->m + link->o;
			return (1);
		}
		g_octet = g_octet + link->m;
		return (1);
	}
	else
		ft_result_letter_u_5(link, p);
	return (1);
}
