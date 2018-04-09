/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 18:26:05 by mimazouz          #+#    #+#             */
/*   Updated: 2016/12/05 19:42:16 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_set_tetri_height(t_tetri *tetri)
{
	int		i;
	int		height;

	i = 0;
	height = 0;
	while (i < 4)
	{
		if (ft_strchr(tetri->array[i], tetri->letter) != NULL)
			height++;
		i++;
	}
	tetri->height = height;
}

void	ft_set_tetri_width(t_tetri *tetri)
{
	int		n;
	int		j;
	int		width;

	n = 0;
	j = 0;
	width = 0;
	while (j < 4)
	{
		if (search_char_column_n(tetri, tetri->letter, n))
			width++;
		n++;
		j++;
	}
	tetri->width = width;
}
