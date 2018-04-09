/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_s_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:15:49 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:20:05 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_result_letter_s_1(t_printf *link, char *str)
{
	if (link->moins >= 0 && link->preci == -1 && link->width == 0 &&
			link->point == -1)
	{
		ft_putstr(str);
		g_octet = g_octet + ft_strlen(str);
		return (1);
	}
	else if (link->moins > 0 && link->preci == -1 && link->width > 0 &&
			link->point == -1)
	{
		ft_putstr(str);
		link->o = ft_strlen(str);
		while (link->m != link->width - link->o && link->width > link->o)
		{
			ft_putchar(' ');
			link->m++;
		}
		g_octet = g_octet + link->o + link->m;
		return (1);
	}
	else
		ft_result_letter_s_2(link, str);
	return (1);
}

int		ft_result_letter_s_2(t_printf *link, char *str)
{
	if (link->moins >= 0 && link->preci == -1 && link->width >= 0 &&
			(link->point == 1 || link->point == 0))
	{
		while (link->m != link->width)
		{
			ft_putchar(' ');
			link->m++;
		}
		g_octet = g_octet + link->m;
		return (1);
	}
	else
		ft_result_letter_s_3(link, str);
	return (1);
}

int		ft_result_letter_s_3(t_printf *link, char *str)
{
	if (link->moins > 0 && link->preci > -1 && link->width >= 0 &&
			link->point == 2)
	{
		link->k = ft_strlen(str);
		while (link->m < link->preci && link->m < link->k)
		{
			ft_putchar(str[link->m]);
			link->m++;
		}
		while (link->o < link->width - link->m)
		{
			ft_putchar(' ');
			link->o++;
		}
		g_octet = g_octet + link->m + link->o;
		return (1);
	}
	else
		ft_result_letter_s_4(link, str);
	return (1);
}

int		ft_result_letter_s_4(t_printf *link, char *str)
{
	if (link->moins == 0 && link->preci == -1 && link->width > 0 &&
			link->point == -1)
	{
		link->o = ft_strlen(str);
		while (link->m != link->width - link->o && link->width > link->o)
		{
			ft_putchar(' ');
			link->m++;
		}
		ft_putstr(str);
		g_octet = g_octet + link->o + link->m;
		return (1);
	}
	else
		ft_result_letter_s_5(link, str);
	return (1);
}

int		ft_result_letter_s_5(t_printf *link, char *str)
{
	if (link->moins == 0 && link->preci > -1 && link->width >= 0 &&
			link->point == 2)
	{
		link->k = ft_strlen(str);
		while (link->m < link->preci && link->m < link->k)
			link->m++;
		while (link->o < link->width - link->m)
		{
			ft_putchar(' ');
			link->o++;
		}
		link->m = 0;
		while (link->m < link->preci && link->m < link->k)
		{
			ft_putchar(str[link->m]);
			link->m++;
		}
		g_octet = g_octet + link->m + link->o;
		return (1);
	}
	else
		return (0);
}
