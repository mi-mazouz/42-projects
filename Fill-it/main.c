/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 14:20:07 by mimazouz          #+#    #+#             */
/*   Updated: 2016/11/29 13:06:17 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(int fd)
{
	if (fd == -1)
		ft_putendl("Error");
	else
	{
		ft_putendl("Error");
		close(fd);
	}
	return (0);
}

int		main(int argc, char **file)
{
	int		fd;
	int		nb_tetri;
	char	**square;
	t_tetri **array;

	fd = -1;
	if (argc != 2)
		return (ft_error(fd));
	fd = open(file[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(fd));
	if (!(nb_tetri = ft_read_tetri(fd)))
		return (ft_error(fd));
	if (close(fd) == -1)
		return (ft_error(fd));
	fd = open(file[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(fd));
	array = ft_copy_tetris(fd, nb_tetri);
	if (close(fd) == -1)
		return (ft_error(fd));
	square = ft_resolve_fillit(array, nb_tetri);
	ft_puttab(square, '\n');
	return (0);
}
