/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 14:57:39 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/16 11:25:50 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_delete_tetri(int i, int j, char **square, t_tetri *tetri)
{
	int	k;
	int	l;

	k = 0;
	while (k < tetri->height)
	{
		l = 0;
		while (l < tetri->width)
		{
			if (tetri->array[k][l] == tetri->letter)
				square[i + k][j + l] = '.';
			l++;
		}
		k++;
	}
}

void	ft_place_tetri(int i, int j, char **square, t_tetri *tetri)
{
	int	k;
	int	l;

	k = 0;
	while (k < tetri->height)
	{
		l = 0;
		while (l < tetri->width)
		{
			if (tetri->array[k][l] == tetri->letter)
				square[i + k][j + l] = tetri->letter;
			l++;
		}
		k++;
	}
}

int		ft_check_place(int i, int j, char **square, t_tetri *tetri)
{
	int	k;
	int	l;

	k = 0;
	while (k < tetri->height)
	{
		l = 0;
		while (l < tetri->width)
		{
			if (tetri->array[k][l] == tetri->letter
					&& square[i + k][j + l] != '.')
				return (0);
			l++;
		}
		k++;
	}
	return (1);
}

int		ft_fill_square(char **square, t_tetri **array, int size, int n)
{
	int	i;
	int	j;

	i = 0;
	if (array[n] == NULL)
		return (1);
	while ((i + array[n]->height) <= size)
	{
		j = 0;
		while ((j + array[n]->width) <= size)
		{
			if (ft_check_place(i, j, square, array[n]))
			{
				ft_place_tetri(i, j, square, array[n]);
				if (!(ft_fill_square(square, array, size, n + 1)))
					ft_delete_tetri(i, j, square, array[n]);
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
