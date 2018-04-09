/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_b_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:25:54 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:16:07 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_result_letter_b_11(t_printf *link, long *p)
{
	if (link->plus >= 0 && link->space >= 0 && link->moins > 0 &&
			link->zero >= 0 && link->preci == -1 && link->width > 0)
	{
		ft_result_letter_b_12(link, p);
		if ((*p != 0 && link->point < 2) || link->point == -1)
			ft_putnbr_bl(*p, 2);
		if (*p == 0 && link->point == 1)
			link->m--;
		while (link->j < link->width - link->o && link->width > link->o)
		{
			ft_putchar(' ');
			link->m++;
		}
		g_octet = g_octet + link->o + link->m;
		return (1);
	}
	else
		ft_result_letter_b_13(link, p);
	return (1);
}

void	ft_result_letter_b_12(t_printf *link, long *p)
{
	if (link->plus > 0 || link->space > 0)
	{
		if (*p >= 0)
		{
			if (link->plus > 0)
				ft_putchar('+');
			else if (link->space > 0)
				ft_putchar(' ');
			link->m++;
		}
	}
	else if (*p != -9223372036854775807 - 1 && *p < 0)
	{
		ft_putchar('-');
		*p = -(*p);
		link->o -= 1;
		link->m++;
	}
}

int		ft_result_letter_b_13(t_printf *link, long *p)
{
	if (link->plus == 0 && link->space == 0 && link->moins == 0 &&
			link->zero >= 0 && link->preci == -1 && link->width > 0)
	{
		if (*p < 0 && link->point < 1 && *p != -9223372036854775807 - 1)
		{
			*p = -(*p);
			ft_putchar('-');
		}
		while (link->m < link->width - link->o && link->width > link->o)
		{
			if ((link->point == 1 && link->zero > 0) || link->zero == 0)
				ft_putchar(' ');
			else
				ft_putchar('0');
			link->m++;
		}
		if ((*p != 0 && link->point < 2) || link->point == -1)
			ft_putnbr_bl(*p, 2);
		g_octet = g_octet + link->o + link->m;
		return (1);
	}
	else
		ft_result_letter_b_14(link, p);
	return (1);
}

int		ft_result_letter_b_14(t_printf *link, long *p)
{
	if (link->plus == 0 && link->space > 0 && link->moins == 0 &&
			link->zero > 0 && link->preci == -1 && link->width > 0)
	{
		ft_result_letter_b_15(link, p);
		while (link->m < link->width - link->o && link->width > link->o)
		{
			if (link->point == 1)
				ft_putchar(' ');
			else
				ft_putchar('0');
			link->m++;
		}
		if (*p == -9223372036854775807 - 1 && link->point == -1)
			ft_putstr("9223372036854775808");
		else if ((*p != 0 && link->point < 2) || link->point == -1)
			ft_putnbr_bl(*p, 2);
		g_octet = g_octet + link->o + link->m;
	}
	return (1);
}

void	ft_result_letter_b_15(t_printf *link, long *p)
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
