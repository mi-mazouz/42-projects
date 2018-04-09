/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_b_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:05:27 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:16:21 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_result_letter_b_5(t_printf *link, long *p)
{
	if (link->plus >= 0 && link->space >= 0 && link->moins >= 0 &&
			link->zero >= 0 && link->preci > -1 && link->width == 0)
	{
		ft_result_letter_b_6(link, p);
		while (link->m < link->preci - link->o)
		{
			ft_putchar('0');
			link->m++;
		}
		if (*p == -9223372036854775807 - 1)
			ft_putstr("9223372036854775808");
		else if ((link->point < 3 && *p != 0) || link->point == -1)
		{
			ft_putnbr_bl(*p, 2);
			g_octet = g_octet + link->m + link->o;
			return (1);
		}
		g_octet = g_octet + link->m;
		return (1);
	}
	else
		ft_result_letter_b_7(link, p);
	return (1);
}

void	ft_result_letter_b_6(t_printf *link, long *p)
{
	if (link->plus > 0 || link->space > 0)
	{
		if (*p >= 0)
		{
			if (link->plus > 0)
				ft_putchar('+');
			else if (link->space > 0)
				ft_putchar(' ');
			g_octet += 1;
		}
	}
	if (*p < 0)
	{
		if (*p != -9223372036854775807 - 1)
			*p = -(*p);
		link->o += -1;
		ft_putchar('-');
		g_octet += 1;
	}
}

int		ft_result_letter_b_7(t_printf *link, long *p)
{
	if (link->plus > 0 && link->space == 0 && link->moins == 0 &&
			link->zero > 0 && link->preci == -1 && link->width > 0)
	{
		ft_result_letter_b_8(link, p);
		if (*p >= 0 && link->point != -1)
			ft_putchar('+');
		if (*p < 0 && link->point != -1 && *p != -9223372036854775807 - 1)
		{
			*p = -(*p);
			ft_putchar('-');
		}
		if (*p == -9223372036854775807 - 1 && link->point == -1)
			ft_putstr("9223372036854775808");
		else if ((link->point < 2 && *p != 0) || link->point == -1)
			ft_putnbr_bl(*p, 2);
		g_octet = g_octet + link->m + link->o;
		return (1);
	}
	else
		ft_result_letter_b_9(link, p);
	return (1);
}

void	ft_result_letter_b_8(t_printf *link, long *p)
{
	if ((*p >= 0 && link->point == -1) || (*p > 0 && link->point == 1))
		link->m++;
	if (*p >= 0 && link->point == -1)
		ft_putchar('+');
	if (*p < 0 && link->point == -1 && *p != -9223372036854775807 - 1)
	{
		*p = -(*p);
		ft_putchar('-');
	}
	if (*p == -9223372036854775807 - 1 && link->point == -1)
		ft_putchar('-');
	while (link->m < link->width - link->o)
	{
		if (link->point == -1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		link->m++;
	}
}

int		ft_result_letter_b_9(t_printf *link, long *p)
{
	if (link->plus >= 0 && link->space >= 0 && link->moins > 0 &&
			link->zero == 0 && link->preci > -1 && link->width > 0)
	{
		ft_result_letter_b_10(link, p);
		while (link->m < link->preci - link->o && link->preci > link->o)
		{
			ft_putchar('0');
			link->m++;
		}
		ft_putnbr_bl(*p, 2);
		while (link->k < link->width - link->preci && link->width > link->o)
		{
			ft_putchar(' ');
			link->k++;
		}
		g_octet = g_octet + link->o + link->m + link->k;
		return (1);
	}
	else
		ft_result_letter_b_11(link, p);
	return (1);
}
