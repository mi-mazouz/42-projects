/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:33:13 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:19:52 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_result_letter_s(t_printf *link, va_list ap)
{
	char	*str;

	link->o = 0;
	link->m = 0;
	if (link->l == 1 || link->letter == 'S')
	{
		ft_result_letter_tall_s(link, ap);
		return (1);
	}
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		g_octet = g_octet + 6;
		return (1);
	}
	else
		ft_result_letter_s_1(link, str);
	return (1);
}

int		ft_result_letter_tall_s(t_printf *link, va_list ap)
{
	int		p;
	wchar_t *s;

	p = 0;
	link->m = 0;
	link->k = 0;
	link->o = 0;
	s = (wchar_t *)va_arg(ap, int *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		g_octet = g_octet + 6;
		return (1);
	}
	else
		ft_result_letter_tall_s_1(link, s, &p);
	return (1);
}

int		ft_result_letter_tall_s_1(t_printf *link, wchar_t *s, int *p)
{
	if (link->moins >= 0 && link->preci == -1 && link->width == 0 &&
			link->point == -1)
	{
		while (s[link->o] != 0)
		{
			*p = s[link->o];
			g_octet = g_octet + ft_return_octet(*p);
			ft_conv_wchar(s[link->o]);
			link->o++;
		}
		return (1);
	}
	else
		ft_result_letter_tall_s_2(link, s, p);
	return (1);
}

int		ft_result_letter_tall_s_2(t_printf *link, wchar_t *s, int *p)
{
	if (link->moins > 0 && link->preci == -1 && link->width > 0 &&
			link->point == -1)
	{
		while (s[link->o] != 0)
		{
			*p = s[link->o];
			g_octet = g_octet + ft_return_octet(*p);
			ft_conv_wchar(s[link->o]);
			link->o++;
		}
		while (link->m != link->width - g_octet && link->width > g_octet)
		{
			ft_putchar(' ');
			link->m++;
		}
		g_octet = g_octet + link->m;
		return (1);
	}
	else
		ft_result_letter_tall_s_3(link, s, p);
	return (1);
}

int		ft_result_letter_tall_s_3(t_printf *link, wchar_t *s, int *p)
{
	if (link->moins >= 0 && link->preci == -1 && link->width >= 0 &&
			(link->point == 1 || link->point == 0))
	{
		while (link->o != link->width)
		{
			ft_putchar(' ');
			link->o++;
		}
		g_octet = g_octet + link->o;
		return (1);
	}
	else
		ft_result_letter_tall_s_4(link, s, p);
	return (1);
}
