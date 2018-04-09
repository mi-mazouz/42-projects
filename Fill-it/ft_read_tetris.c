/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 14:21:00 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/13 18:44:05 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read_tetri(int fd)
{
	int		nb_tetri;
	int		oct;
	int		oct2;
	char	buf[21];
	char	buf2[2];

	nb_tetri = 0;
	oct = 0;
	oct2 = 0;
	ft_bzero((void *)buf, 21);
	ft_bzero((void *)buf2, 2);
	while ((oct = read(fd, buf, 20)) > 0)
	{
		if (!ft_check_file(buf))
			return (0);
		if ((oct2 = read(fd, buf2, 1)) == 1 && buf2[0] != '\n')
			return (0);
		nb_tetri++;
	}
	if (oct2 == 1)
		return (0);
	return (nb_tetri);
}
