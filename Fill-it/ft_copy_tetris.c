/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_tetris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 15:35:32 by mimazouz          #+#    #+#             */
/*   Updated: 2016/03/18 16:55:50 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_fill_array(char *buf, t_tetri *tetri, char letter)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	ft_replace_char(buf, '\n', '\0');
	tetri->letter = letter;
	while (i < 4)
	{
		ft_strncpy(tetri->array[i], buf + j, 5);
		ft_replace_char(tetri->array[i], '#', letter);
		i++;
		j = j + 5;
	}
}

t_tetri		*ft_init_tetri(char *buf, char letter)
{
	t_tetri	*tetri;

	tetri = (t_tetri *)malloc(sizeof(t_tetri));
	ft_fill_array(buf, tetri, letter);
	ft_put_blocks_up(tetri);
	ft_put_blocks_left(tetri);
	ft_set_tetri_height(tetri);
	ft_set_tetri_width(tetri);
	return (tetri);
}

t_tetri		**ft_copy_tetris(int fd, int nb_tetri)
{
	t_tetri	**tetris_array;
	char	buf[21];
	char	buf2[2];
	int		i;

	i = 0;
	ft_bzero((void *)buf, 21);
	ft_bzero((void *)buf2, 2);
	tetris_array = (t_tetri **)malloc(sizeof(t_tetri *) * (nb_tetri + 1));
	if (!tetris_array)
		return (0);
	while (i < nb_tetri)
	{
		read(fd, buf, 20);
		tetris_array[i] = ft_init_tetri(buf, 'A' + i);
		read(fd, buf2, 1);
		i++;
	}
	tetris_array[nb_tetri] = NULL;
	return (tetris_array);
}
