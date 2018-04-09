/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_block_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 18:04:59 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:14:33 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_order_flags(t_printf *b)
{
	int i;
	int flags;
	int point;

	point = 0;
	flags = 0;
	i = 0;
	while (b->flags[i] != 0)
	{
		if (b->flags[i] == '.')
			point++;
		else if (ft_check_order_flags_2(b, &flags, i) == 0)
			return (0);
		i++;
	}
	if (point > 1)
		return (0);
	return (1);
}

int		ft_check_order_flags_2(t_printf *b, int *flags, int i)
{
	if (ft_check_char(b->flags[i]) == 1)
	{
		if (b->flags[i] == '0' && *flags == 2)
			*flags = 2;
		else if (*flags > 1)
			return (0);
		else
			*flags = 1;
	}
	else if (ft_check_char_2(b->flags[i]) == 1)
	{
		if (*flags > 2)
			return (0);
		*flags = 2;
	}
	else if (ft_check_char_3(b->flags[i]) == 1)
	{
		if (*flags > 3)
			return (0);
		*flags = 3;
	}
	else if (ft_check_char_4(b->flags[i]) == 1)
		*flags = 4;
	return (1);
}

int		ft_verif(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
