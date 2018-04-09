/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:31:21 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/26 12:32:30 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int			ft_choose_read(t_filler *filler, int *pos, int *close)
{
	if (close[0] >= pos[0])
	{
		if (close[1] <= pos[1])
			return (ft_read_shape_top_left(filler, pos));
		else
			return (ft_read_shape_top_right(filler, pos));
	}
	else
	{
		if (close[1] <= pos[1])
			return (ft_read_shape_bottom_left(filler, pos));
		else
			return (ft_read_shape_bottom_right(filler, pos));
	}
}


int		ft_read_shape_bottom_left(t_filler *filler, int *pos)
{
	int	i;
	int j;

	i = 0;
	while (filler->piece.tab[i] != NULL)
	{
		j = ft_strlen(filler->piece.tab[i]) - 1;
		while (j > -1)
		{
			if (filler->piece.tab[i][j] == '*')
				if (ft_move_for_check(filler, i, j, pos) == 1)
					return (1);
			j--;
		}
		i++;
	}
	return (-1);
}

int		ft_read_shape_bottom_right(t_filler *filler, int *pos)
{
	int	i;
	int j;

	i = 0;
	while (filler->piece.tab[i] != NULL)
	{
		j = 0;
		while (filler->piece.tab[i][j] != 0)
		{
			if (filler->piece.tab[i][j] == '*')
				if (ft_move_for_check(filler, i, j, pos) == 1)
					return (1);
			j++;
		}
		i++;
	}
	return (-1);
}

int		ft_read_shape_top_left(t_filler *filler, int *pos)
{
	int	i;
	int j;

	i = ft_tablen(filler->piece.tab) - 1;
	while (i > -1)
	{
		j = ft_strlen(filler->piece.tab[i]) - 1;
		while (j > -1)
		{
			if (filler->piece.tab[i][j] == '*')
				if (ft_move_for_check(filler, i, j, pos) == 1)
					return (1);
			j--;
		}
		i--;
	}
	return (-1);
}

int		ft_read_shape_top_right(t_filler *filler, int *pos)
{
	int	i;
	int j;

	i = ft_tablen(filler->piece.tab) - 1;
	while (i > -1)
	{
		j = 0;
		while (filler->piece.tab[i][j] != 0)
		{
			if (filler->piece.tab[i][j] == '*')
				if (ft_move_for_check(filler, i, j, pos) == 1)
					return (1);
			j++;
		}
		i--;
	}
	return (-1);
}
