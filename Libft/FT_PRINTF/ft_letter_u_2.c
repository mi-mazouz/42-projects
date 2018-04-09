/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_u_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:58:28 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:20:51 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_result_letter_u_5(t_printf *link, unsigned long *p)
{
	if (link->moins == 0 && link->zero > 0 && link->preci == -1 &&
			link->width > 0)
	{
		if (link->point == -1 || (*p != 0 && link->point == 1))
			link->m++;
		if (link->point == -1)
			link->m--;
		while (link->m < link->width - link->o)
		{
			if (link->point == -1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			link->m++;
		}
		if (link->point != -1)
			ft_putchar('+');
		if ((link->point < 2 && *p != 0) || link->point == -1)
			ft_putnbr_base_unsigned_long(*p, 10);
		g_octet = g_octet + link->m + link->o;
		return (1);
	}
	else
		ft_result_letter_u_6(link, p);
	return (1);
}

int		ft_result_letter_u_6(t_printf *link, unsigned long *p)
{
	if (link->moins > 0 && link->zero == 0 && link->preci > -1 &&
			link->width > 0)
	{
		while (link->m < link->preci - link->o)
		{
			ft_putchar('0');
			link->m++;
		}
		ft_putnbr_base_unsigned_long(*p, 10);
		while (link->k < link->width - link->preci && link->width > link->o)
		{
			ft_putchar(' ');
			link->k++;
		}
		g_octet = g_octet + link->o + link->m + link->k;
		return (1);
	}
	else
		ft_result_letter_u_7(link, p);
	return (1);
}

int		ft_result_letter_u_7(t_printf *link, unsigned long *p)
{
	if (link->moins > 0 && link->zero >= 0 && link->preci == -1 &&
			link->width > 0)
	{
		if ((*p != 0 && link->point < 2) || link->point == -1)
			ft_putnbr_base_unsigned_long(*p, 10);
		if (*p == 0 && link->point == 1)
			link->m--;
		while (link->m < link->width - link->o && link->width > link->o)
		{
			ft_putchar(' ');
			link->m++;
		}
		g_octet = g_octet + link->o + link->m;
		return (1);
	}
	else
		ft_result_letter_u_8(link, p);
	return (1);
}

int		ft_result_letter_u_8(t_printf *link, unsigned long *p)
{
	if (link->moins == 0 && link->zero >= 0 && link->preci == -1 &&
			link->width > 0)
	{
		if (*p == 0 && link->point == 1)
			link->m--;
		while (link->m < link->width - link->o && link->width > link->o)
		{
			if ((link->point == 1 && link->zero > 0) || link->zero == 0)
				ft_putchar(' ');
			else
				ft_putchar('0');
			link->m++;
		}
		if ((*p != 0 && link->point < 2) || link->point == -1)
			ft_putnbr_base_unsigned_long(*p, 10);
		g_octet = g_octet + link->o + link->m;
		return (1);
	}
	else
		ft_result_letter_u_9(link, p);
	return (1);
}

int		ft_result_letter_u_9(t_printf *link, unsigned long *p)
{
	if (link->moins == 0 && link->zero > 0 && link->preci == -1 &&
			link->width > 0)
	{
		if (*p == 0 && link->point == 1)
			link->m--;
		ft_putchar(' ');
		link->m++;
		while (link->m < link->width - link->o && link->width > link->o)
		{
			if (link->point == 1)
				ft_putchar(' ');
			else
				ft_putchar('0');
			link->m++;
		}
		if ((*p != 0 && link->point < 2) || link->point == -1)
			ft_putnbr_base_unsigned_long(*p, 10);
		g_octet = g_octet + link->o + link->m;
	}
	return (1);
}
