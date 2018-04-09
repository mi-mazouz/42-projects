/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_%.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 18:55:15 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:19:39 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_result_letter_percent(t_printf *link)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (link->moins == 0)
	{
		while (j < link->width - i && link->width > i)
		{
			if (link->zero == 0)
				ft_putchar(' ');
			else
				ft_putchar('0');
			j++;
		}
		ft_putchar(link->letter);
		g_octet = g_octet + i + j;
	}
	else
		ft_result_letter_percent_2(link, &j, i);
	return (1);
}

void	ft_result_letter_percent_2(t_printf *link, int *j, int i)
{
	ft_putchar(link->letter);
	while (*j < link->width - i && link->width > i)
	{
		if (link->zero == 0)
			ft_putchar(' ');
		else
			ft_putchar('0');
		(*j)++;
	}
	g_octet = g_octet + i + *j;
}
