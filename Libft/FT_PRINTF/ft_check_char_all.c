/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 13:35:16 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:14:56 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_char(char c)
{
	char	*tab;
	int		i;

	tab = ft_strdup("#0-+ ");
	i = 0;
	while (tab[i] != 0)
	{
		if (tab[i] == c)
		{
			free(tab);
			return (1);
		}
		i++;
	}
	free(tab);
	return (0);
}

int		ft_check_char_2(char c)
{
	char	*tab;
	int		i;

	tab = ft_strdup("0123456789");
	i = 0;
	while (tab[i] != 0)
	{
		if (tab[i] == c)
		{
			free(tab);
			return (1);
		}
		i++;
	}
	free(tab);
	return (0);
}

int		ft_check_char_3(char c)
{
	char	*tab;
	int		i;

	tab = ft_strdup("lhjz");
	i = 0;
	while (tab[i] != 0)
	{
		if (tab[i] == c)
		{
			free(tab);
			return (1);
		}
		i++;
	}
	free(tab);
	return (0);
}

int		ft_check_char_4(char c)
{
	char	*tab;
	int		i;

	tab = ft_strdup("%sSdDbipoOuUxXcC");
	i = 0;
	while (tab[i] != 0)
	{
		if (tab[i] == c)
		{
			free(tab);
			return (1);
		}
		i++;
	}
	free(tab);
	return (0);
}

int		ft_check_char_5(char c)
{
	char	*tab;
	int		i;

	tab = ft_strdup("-+# %hjlzsSdDbipoOuUxXcC0123456789.");
	i = 0;
	while (tab[i] != 0)
	{
		if (tab[i] == c)
		{
			free(tab);
			return (1);
		}
		i++;
	}
	free(tab);
	return (0);
}
