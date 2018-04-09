/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_wchar_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 19:57:19 by mimazouz          #+#    #+#             */
/*   Updated: 2016/03/31 16:15:35 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fill_tab(char **tab, int i)
{
	if (i == 1)
		*tab = ft_strdup("0xxxxxxx");
	else if (i == 2)
		*tab = ft_strdup("110xxxxx10xxxxxx");
	else if (i == 3)
		*tab = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	else
		*tab = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
}

void	ft_conv_decimal_1(char *tab, int i)
{
	int	power;
	int value;

	value = 0;
	power = 7;
	while (i < 8)
	{
		if (tab[i] == '0')
			power--;
		else
		{
			value = value + (ft_power(2, power));
			power--;
		}
		i++;
	}
	ft_putint(value);
}

void	ft_conv_decimal_2(char *tab, int i)
{
	int	power;
	int value;

	value = 0;
	power = 7;
	ft_conv_decimal_1(tab, 0);
	while (i < 16)
	{
		if (tab[i] == '0')
			power--;
		else
		{
			value = value + (ft_power(2, power));
			power--;
		}
		i++;
	}
	ft_putint(value);
}

void	ft_conv_decimal_3(char *tab, int i)
{
	int	power;
	int value;

	value = 0;
	power = 7;
	ft_conv_decimal_2(tab, 8);
	while (i < 24)
	{
		if (tab[i] == '0')
			power--;
		else
		{
			value = value + (ft_power(2, power));
			power--;
		}
		i++;
	}
	ft_putint(value);
}

void	ft_conv_decimal_4(char *tab, int i)
{
	int	power;
	int value;

	value = 0;
	power = 7;
	ft_conv_decimal_3(tab, 16);
	while (i < 32)
	{
		if (tab[i] == '0')
			power--;
		else
		{
			value = value + (ft_power(2, power));
			power--;
		}
		i++;
	}
	ft_putint(value);
}
