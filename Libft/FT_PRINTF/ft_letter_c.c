/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 17:04:32 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:16:36 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_result_letter_c_2(t_printf *link, int p, int i, int j)
{
	if (link->width > 0 && link->moins == 0)
	{
		while (j != link->width - i && link->width > i)
		{
			ft_putchar(' ');
			j++;
		}
		g_octet = g_octet + i + j;
		ft_putchar(p);
		return (1);
	}
	else if (link->width > 0 && link->moins > 0)
	{
		ft_putchar(p);
		while (j != link->width - i && link->width > i)
		{
			ft_putchar(' ');
			j++;
		}
		g_octet = g_octet + i + j;
		return (1);
	}
	return (0);
}

int			ft_result_letter_c(t_printf *link, va_list ap)
{
	int p;
	int i;
	int j;

	j = 0;
	if (link->l == 1 || link->letter == 'C')
	{
		ft_result_letter_tall_c(link, ap);
		return (1);
	}
	p = (char)va_arg(ap, int);
	i = ft_return_octet(p);
	if (link->width == 0 && link->moins >= 0)
	{
		g_octet = g_octet + ft_return_octet(p);
		ft_putchar(p);
		return (1);
	}
	else if (ft_result_letter_c_2(link, p, i, j) == 1)
		return (1);
	return (0);
}

static int	ft_result_letter_tall_c_2(t_printf *link, int p, int i, int j)
{
	if (link->width > 0 && link->moins == 0)
	{
		while (j != link->width - i && link->width > i)
		{
			ft_putchar(' ');
			j++;
		}
		g_octet = g_octet + i + j;
		ft_conv_wchar(p);
		return (1);
	}
	else if (link->width > 0 && link->moins > 0)
	{
		ft_conv_wchar(p);
		while (j != link->width - i && link->width > i)
		{
			ft_putchar(' ');
			j++;
		}
		g_octet = g_octet + i + j;
		return (1);
	}
	return (0);
}

int			ft_result_letter_tall_c(t_printf *link, va_list ap)
{
	int j;
	int p;
	int i;

	i = 0;
	j = 0;
	p = va_arg(ap, wchar_t);
	i = ft_return_octet(p);
	if (link->width == 0 && link->moins >= 0)
	{
		g_octet = g_octet + ft_return_octet(p);
		ft_conv_wchar(p);
		return (1);
	}
	else if (ft_result_letter_tall_c_2(link, p, i, j) == 1)
		return (1);
	return (0);
}
