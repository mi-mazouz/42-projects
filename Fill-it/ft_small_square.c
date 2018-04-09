/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:23:18 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/16 11:19:13 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_square_size(int nb_tetri)
{
	int	size;

	size = 2;
	while (size * size < (nb_tetri * 4))
		size++;
	return (size);
}

char	**ft_init_square(int size)
{
	int		l;
	int		j;
	char	**square;

	l = 0;
	if (!(square = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (l < size)
	{
		if (!(square[l] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		l++;
	}
	l--;
	while (l >= 0)
	{
		j = 0;
		while (j < size)
			square[l][j++] = '.';
		square[l][j] = '\0';
		l--;
	}
	square[size] = NULL;
	return (square);
}

char	**ft_resolve_fillit(t_tetri **array, int nb_tetri)
{
	char	**square;
	int		size;
	int		i;

	i = 0;
	size = ft_square_size(nb_tetri);
	square = ft_init_square(size);
	while (!(ft_fill_square(square, array, size, 0)))
	{
		size++;
		i = 0;
		while (square[i])
		{
			free(square[i]);
			i++;
		}
		free(square);
		square = ft_init_square(size);
	}
	return (square);
}
