/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_s_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:25:30 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:20:19 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_result_letter_tall_s_4(t_printf *link, wchar_t *s, int *p)
{
	if (link->moins > 0 && link->preci > -1 && link->width >= 0 &&
			link->point == 2)
	{
		while (s[link->o] != 0)
		{
			*p = s[link->o];
			link->k = link->k + ft_return_octet(*p);
			if (link->k > link->preci)
				break ;
			ft_conv_wchar(s[link->o]);
			g_octet = g_octet + ft_return_octet(*p);
			link->o++;
		}
		while (link->m < link->width - g_octet && link->width > g_octet)
		{
			ft_putchar(' ');
			link->m++;
		}
		g_octet = g_octet + link->m;
		return (1);
	}
	else
		ft_result_letter_tall_s_5(link, s, p);
	return (1);
}

int		ft_result_letter_tall_s_5(t_printf *link, wchar_t *s, int *p)
{
	if (link->moins == 0 && link->preci == -1 && link->width > 0 &&
			link->point == -1)
	{
		while (s[link->o] != 0)
		{
			*p = s[link->o];
			g_octet = g_octet + ft_return_octet(*p);
			link->o++;
		}
		while (link->m != link->width - g_octet && link->width > g_octet)
		{
			ft_putchar(' ');
			link->m++;
		}
		while (s[link->k] != 0)
		{
			ft_conv_wchar(s[link->k]);
			link->k++;
		}
		g_octet = g_octet + link->m;
		return (1);
	}
	else
		ft_result_letter_tall_s_6(link, s, p);
	return (1);
}

int		ft_result_letter_tall_s_6(t_printf *link, wchar_t *s, int *p)
{
	if (link->moins == 0 && link->preci > -1 && link->width >= 0 &&
			link->point == 2)
	{
		ft_result_letter_tall_s_7(link, s, p);
		while (s[link->o] != 0)
		{
			*p = s[link->o];
			link->k = link->k + ft_return_octet(*p);
			if (link->k > link->preci)
				break ;
			ft_conv_wchar(s[link->o]);
			g_octet = g_octet + ft_return_octet(*p);
			link->k++;
		}
		g_octet = g_octet + link->m;
	}
	return (1);
}

void	ft_result_letter_tall_s_7(t_printf *link, wchar_t *s, int *p)
{
	while (s[link->o] != 0)
	{
		*p = s[link->o];
		link->k = link->k + ft_return_octet(*p);
		*p = s[link->o + 1];
		*p = ft_return_octet(*p);
		if (link->k + *p > link->preci)
			break ;
		link->o++;
	}
	while (link->m < link->width - link->k)
	{
		ft_putchar(' ');
		link->m++;
	}
	link->o = 0;
	link->k = 0;
}
