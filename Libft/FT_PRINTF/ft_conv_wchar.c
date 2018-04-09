/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 19:56:35 by mimazouz          #+#    #+#             */
/*   Updated: 2016/09/01 19:40:13 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_conv_wchar(wchar_t value)
{
	unsigned int	j;
	unsigned int	i;
	char			*str;
	char			*tab;

	str = (char *)malloc(sizeof(char) * 33);
	ft_strclr(str, 33);
	j = 31;
	i = (unsigned int)value;
	while (i > 0)
	{
		str[j] = (i % 2) + 48;
		i = i / 2;
		j--;
	}
	tab = ft_masks_unicode(str);
	free(str);
	ft_conv_decimal(tab);
}

void	ft_conv_decimal(char *tab)
{
	int t;

	t = ft_strlen(tab);
	if (t == 8)
		ft_conv_decimal_1(tab, 0);
	else if (t == 16)
		ft_conv_decimal_2(tab, 8);
	else if (t == 24)
		ft_conv_decimal_3(tab, 16);
	else
		ft_conv_decimal_4(tab, 32);
	free(tab);
}

char	*ft_masks_unicode(char *str)
{
	char	*tab;

	if (ft_nb_octet(str) <= 7)
	{
		ft_fill_tab(&tab, 1);
		ft_fill_masks(str, tab);
	}
	else if (ft_nb_octet(str) <= 11)
	{
		ft_fill_tab(&tab, 2);
		ft_fill_masks(str, tab);
	}
	else if (ft_nb_octet(str) <= 16)
	{
		ft_fill_tab(&tab, 3);
		ft_fill_masks(str, tab);
	}
	else
	{
		ft_fill_tab(&tab, 4);
		ft_fill_masks(str, tab);
	}
	return (tab);
}

void	ft_fill_masks(char *str, char *tab)
{
	int i;
	int j;

	j = 31;
	i = ft_strlen(tab);
	i = i - 1;
	while (i > 0)
	{
		if (tab[i] == 'x' && str[j] != '\0')
		{
			tab[i] = str[j];
			i--;
			j--;
		}
		else if (str[j] == '\0' && tab[i] == 'x')
		{
			tab[i] = '0';
			i--;
		}
		else if (tab[i] == '1' || tab[i] == '0')
			i--;
	}
}

int		ft_nb_octet(char *str)
{
	int i;
	int nb_octet;

	i = 31;
	nb_octet = 0;
	while (str[i] != 0)
	{
		i--;
		nb_octet++;
	}
	return (nb_octet);
}
