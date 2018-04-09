/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_x_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:02:18 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:21:18 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_result_letter_x_6(t_printf *link, unsigned long *p)
{
	if (link->moins >= 0 && link->zero >= 0 && link->preci > -1 &&
			link->width == 0)
	{
		ft_result_letter_x_7(link, p);
		if ((link->point < 3 && *p != 0) || link->point == -1)
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
		ft_result_letter_x_8(link, p);
	return (1);
}

void	ft_result_letter_x_7(t_printf *link, unsigned long *p)
{
	if (link->htag > 0 && *p != 0)
	{
		if (link->letter == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		link->m += 2;
	}
	while (link->m < link->preci - link->o)
	{
		ft_putchar('0');
		link->m++;
	}
}

int		ft_result_letter_x_8(t_printf *link, unsigned long *p)
{
	if (link->moins == 0 && link->zero > 0 && link->preci == -1 &&
			link->width > 0)
	{
		ft_result_letter_x_9(link);
		if ((link->point < 2 && *p != 0) || link->point == -1)
		{
			if (link->letter == 'X')
				ft_putnbr_bul(*p, 16);
			else
				ft_putnbr_base_unsigned_long(*p, 16);
		}
		g_octet = g_octet + link->m + link->o;
		return (1);
	}
	else
		ft_result_letter_x_10(link, p);
	return (1);
}

void	ft_result_letter_x_9(t_printf *link)
{
	if (link->htag > 0)
	{
		if (link->letter == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		link->m += 2;
	}
	while (link->m < link->width - link->o)
	{
		if (link->point == -1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		link->m++;
	}
}

int		ft_result_letter_x_10(t_printf *link, unsigned long *p)
{
	if (link->moins > 0 && link->zero == 0 && link->preci > -1 &&
			link->width > 0)
	{
		ft_result_letter_x_11(link);
		if (link->letter == 'X')
			ft_putnbr_bul(*p, 16);
		else
			ft_putnbr_base_unsigned_long(*p, 16);
		while (link->k < link->width - link->preci && link->width > link->o)
		{
			ft_putchar(' ');
			link->k++;
		}
		g_octet = g_octet + link->o + link->m + link->k;
		return (1);
	}
	else
		ft_result_letter_x_12(link, p);
	return (1);
}
