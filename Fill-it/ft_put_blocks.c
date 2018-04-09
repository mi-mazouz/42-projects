/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_blocks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 19:31:10 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/16 10:39:45 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_put_blocks_up(t_tetri *tetri)
{
	int	i;

	while (ft_strchr(tetri->array[0], tetri->letter) == NULL)
	{
		i = 0;
		while (i < 3)
		{
			ft_strcpy(tetri->array[i], tetri->array[i + 1]);
			i++;
		}
		ft_strcpy(tetri->array[3], "....");
	}
}

void	ft_put_blocks_left(t_tetri *tetri)
{
	int	i;
	int	j;

	while (!(search_char_column_n(tetri, tetri->letter, 0)))
	{
		j = 0;
		while (j < 3)
		{
			i = 0;
			while (i < 4)
			{
				tetri->array[i][j] = tetri->array[i][j + 1];
				i++;
			}
			j++;
		}
		i = 0;
		while (i < 4)
		{
			tetri->array[i][3] = '.';
			i++;
		}
	}
}

int		search_char_column_n(t_tetri *tetri, char c, int n)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tetri->array[i][n] == c)
			return (1);
		i++;
	}
	return (0);
}
