/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curs_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 10:38:27 by MrRobot           #+#    #+#             */
/*   Updated: 2016/06/07 16:34:12 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_curs_pos_col(int fd)
{
	int				i;
	int				col;
	struct termios	term_curs;
	struct termios	term_set;
	char			*buf;

	i = 0;
	col = 0;
	buf = ft_strnew(16);
	ft_modif_term(&term_curs, 1);
	write(fd, "\033[6n", 4);
	read(fd, buf, 16);
	while (buf[i] && ft_isdigit(buf[i]) == 0)
		i++;
	while (buf[i] && ft_isdigit(buf[i]) == 1)
		i++;
	while (buf[i] && ft_isdigit(buf[i]) == 0)
		i++;
	while (buf[i] && ft_isdigit(buf[i]) == 1)
		col = col * 10 + buf[i++] - 48;
	ft_modif_term(&term_set, 0);
	free(buf);
	return (col);
}

int		ft_curs_pos_row(int fd)
{
	int				i;
	int				row;
	struct termios	term_curs;
	struct termios	term_set;
	char			*buf;

	i = 0;
	row = 0;
	buf = ft_strnew(16);
	ft_modif_term(&term_curs, 1);
	write(fd, "\033[6n", 4);
	read(fd, buf, 16);
	while (buf[i] && ft_isdigit(buf[i]) == 0)
		i++;
	while (buf[i] && ft_isdigit(buf[i]) == 1)
		row = row * 10 + buf[i++] - 48;
	ft_modif_term(&term_set, 0);
	free(buf);
	return (row);
}
