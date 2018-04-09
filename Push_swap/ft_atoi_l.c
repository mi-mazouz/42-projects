/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:33:37 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/29 15:19:01 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_l(char *str)
{
	long	result;
	int		i;
	int		c;
	int		v;

	v = 0;
	result = 0;
	i = 0;
	c = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		c = i;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - 48;
		v = 1;
		i++;
	}
	if (v == 0)
		return (2147483649);
	return (str[c] == '-' ? -result : result);
}

int		ft_str_size(char *str)
{
	int i;
	int c;

	c = 0;
	while (ft_isspace(str[c]))
		c++;
	if (str[c] == '+' || str[c] == '-')
		c++;
	i = c;
	c = 0;
	while (ft_isdigit(str[i]))
	{
		if (str[i] != '0' || (str[i] == '0' && c > 0))
			c++;
		i++;
	}
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != 0)
		return (0);
	else if (c > 10)
		return (0);
	return (1);
}
