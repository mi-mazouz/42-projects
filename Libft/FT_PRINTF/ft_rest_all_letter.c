/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest_all_letter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:05:47 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:21:49 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_result_letter_x_16(t_printf *link, unsigned long *p)
{
	if (link->moins == 0 && link->zero > 0 && link->preci == -1 &&
			link->width > 0)
	{
		ft_result_letter_x_17(link, p);
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
		return (0);
}

void	ft_result_letter_x_17(t_printf *link, unsigned long *p)
{
	if (*p == 0 && link->point == 1)
		link->m--;
	ft_putchar(' ');
	link->m++;
	if (link->htag > 0)
	{
		if (link->letter == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		link->m += 2;
	}
	while (link->m < link->width - link->o && link->width > link->o)
	{
		if (link->point == 1)
			ft_putchar(' ');
		else
			ft_putchar('0');
		link->m++;
	}
}

void	ft_result_letter_x_5(t_printf *link, unsigned long *p)
{
	if (*p == 0 && link->preci == 0)
		link->m--;
	if (link->htag > 0)
	{
		if (link->letter == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		link->m += 2;
	}
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
}

void	ft_result_letter_b_10(t_printf *link, long *p)
{
	if (link->plus > 0 || link->space > 0)
	{
		if (*p >= 0)
		{
			if (link->plus > 0)
				ft_putchar('+');
			else if (link->space > 0)
				ft_putchar(' ');
			link->k++;
		}
	}
	else if (*p != -9223372036854775807 - 1 && *p < 0)
	{
		ft_putchar('-');
		*p = -(*p);
		link->o--;
		link->k++;
	}
}

void	ft_result_letter_d_15(t_printf *link, long *p)
{
	if (*p == 0 && link->point == 1)
		link->m--;
	if (*p < 0 && link->point < 1 && *p != -9223372036854775807 - 1)
	{
		*p = -(*p);
		ft_putchar('-');
	}
	if (*p == -9223372036854775807 - 1 && link->point == -1)
		ft_putchar('-');
	else if (*p >= 0)
	{
		ft_putchar(' ');
		link->m++;
	}
}
