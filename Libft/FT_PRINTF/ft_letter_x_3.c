/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_x_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:04:44 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:21:27 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_result_letter_x_11(t_printf *link)
{
	if (link->htag > 0)
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

int		ft_result_letter_x_12(t_printf *link, unsigned long *p)
{
	if (link->moins > 0 && link->zero >= 0 && link->preci == -1 &&
			link->width > 0)
	{
		ft_result_letter_x_13(link, p);
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
		ft_result_letter_x_14(link, p);
	return (1);
}

void	ft_result_letter_x_13(t_printf *link, unsigned long *p)
{
	if (link->htag > 0)
	{
		if (link->letter == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		link->m += 2;
	}
	if ((*p != 0 && link->point < 2) || link->point == -1)
	{
		if (link->letter == 'X')
			ft_putnbr_bul(*p, 16);
		else
			ft_putnbr_base_unsigned_long(*p, 16);
	}
}

int		ft_result_letter_x_14(t_printf *link, unsigned long *p)
{
	if (link->moins == 0 && link->zero >= 0 && link->preci == -1 &&
			link->width > 0)
	{
		ft_result_letter_x_15(link, p);
		if ((*p != 0 && link->point < 2) || link->point == -1)
		{
			if (link->letter == 'X')
				ft_putnbr_bul(*p, 16);
			else
				ft_putnbr_base_unsigned_long(*p, 16);
		}
		g_octet = g_octet + link->o + link->m;
		return (1);
	}
	else
		ft_result_letter_x_16(link, p);
	return (1);
}

void	ft_result_letter_x_15(t_printf *link, unsigned long *p)
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
}
