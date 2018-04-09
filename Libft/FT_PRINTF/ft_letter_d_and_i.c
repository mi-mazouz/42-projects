/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_d_and_i.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 14:44:32 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:16:58 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_result_letter_d(t_printf *link, va_list ap)
{
	long	p;

	link->m = 0;
	link->k = 0;
	p = ft_return_type(link, ap);
	link->o = (int)ft_strlen(ft_itoa_bl(p, 10));
	if (link->plus >= 0 && link->space >= 0 && link->moins == 0 &&
			link->zero == 0 && link->preci == -1 && link->width > 0)
	{
		ft_result_letter_d_1(link, &p);
		if ((link->point < 2 && p != 0) || link->point == -1)
		{
			ft_putnbr_bl(p, 10);
			g_octet = g_octet + link->m + link->o;
			return (1);
		}
		g_octet = g_octet + link->m;
		return (1);
	}
	else
		ft_result_letter_d_2(link, &p);
	return (1);
}

void	ft_result_letter_d_1(t_printf *link, long *p)
{
	if (*p == 0 && link->point == 1)
		link->m--;
	if (link->space > 0 || link->plus > 0)
		if ((*p >= 0 && link->point == -1) || (*p > 0 && link->point == 1))
			link->m++;
	while (link->m < link->width - link->o && link->width > link->o)
	{
		ft_putchar(' ');
		link->m++;
	}
	if (*p >= 0 && link->point == -1)
	{
		if (link->plus > 0)
			ft_putchar('+');
		else if (link->space > 0)
			ft_putchar(' ');
	}
	if (*p == 0 && link->point != -1)
	{
		if (link->plus > 0)
			ft_putchar('+');
		else if (link->space > 0)
			ft_putchar(' ');
		link->m++;
	}
}

int		ft_result_letter_d_2(t_printf *link, long *p)
{
	if (link->plus >= 0 && link->space >= 0 && link->moins >= 0 &&
			link->zero >= 0 && link->preci == -1 && link->width == 0)
	{
		if (*p >= 0 && (link->plus > 0 || link->space > 0))
		{
			if (link->plus > 0)
				ft_putchar('+');
			else if (link->space > 0)
				ft_putchar(' ');
			link->m++;
		}
		if ((link->point < 2 && *p != 0) || link->point == -1)
		{
			ft_putnbr_bl(*p, 10);
			g_octet = g_octet + link->m + link->o;
			return (1);
		}
		g_octet = g_octet + link->m;
		return (1);
	}
	else
		ft_result_letter_d_3(link, p);
	return (1);
}

int		ft_result_letter_d_3(t_printf *link, long *p)
{
	if (link->plus >= 0 && link->space >= 0 && link->moins == 0 &&
			link->zero >= 0 && link->preci > -1 && link->width > 0)
	{
		if (link->plus > 0 || link->space > 0)
		{
			if (*p >= 0)
				link->m++;
		}
		ft_result_letter_d_4(link, p);
		while (link->k < link->preci - link->o)
		{
			ft_putchar('0');
			link->k++;
		}
		if (*p == -9223372036854775807 - 1)
			ft_putstr("9223372036854775808");
		else if (*p != 0 || (*p == 0 && link->point != 1 && link->preci > 0))
			ft_putnbr_bl(*p, 10);
		g_octet = g_octet + link->m + link->o + link->k;
		return (1);
	}
	else
		ft_result_letter_d_5(link, p);
	return (1);
}

void	ft_result_letter_d_4(t_printf *link, long *p)
{
	if (*p == 0 && link->preci == 0)
		link->m--;
	if (*p < 0 && link->preci >= link->o)
		link->m++;
	while (link->m < link->width - link->o &&
			link->m < link->width - link->preci)
	{
		ft_putchar(' ');
		link->m++;
	}
	if (*p >= 0)
	{
		if (link->plus > 0)
			ft_putchar('+');
		else if (link->space > 0)
			ft_putchar(' ');
	}
	if (*p < 0)
	{
		if (*p != -9223372036854775807 - 1)
			*p = -(*p);
		if (link->preci >= link->o)
			link->k--;
		ft_putchar('-');
	}
}
