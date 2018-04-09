/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:03:59 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/14 10:59:39 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_tetri(char *str, char c)
{
	int	i;
	int	neighbour;
	int	nb_c;

	i = 0;
	neighbour = 0;
	nb_c = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			nb_c++;
			if (i >= 5 && str[i - 5] == c)
				neighbour++;
			if (i <= 15 && str[i + 5] == c)
				neighbour++;
			if (i >= 1 && str[i - 1] == c)
				neighbour++;
			if (i <= 19 && str[i + 1] == c)
				neighbour++;
		}
		i++;
	}
	return (nb_c == 4 && (neighbour == 6 || neighbour == 8));
}

int		ft_check_file(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != '\n' && j < 4)
		{
			if (str[i] != '#' && str[i] != '.')
				return (0);
			j++;
			i++;
		}
		if (str[i] == '\n' && j == 4)
			i++;
		else
			return (0);
	}
	return (ft_check_tetri(str, '#'));
}
