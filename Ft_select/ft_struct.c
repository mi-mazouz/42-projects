/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:40:35 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/06 10:21:40 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_init_struct(t_select *sel)
{
	int	fd;

	sel->lev = 0;
	sel->bot = 0;
	sel->top = 0;
	sel->right = 0;
	sel->left = 0;
	sel->max = ft_return_msd(sel->file);
	sel->curs = sel->file;
	if (sel->win.ws_col > (sel->max + 1))
		sel->col = (sel->win.ws_col / (sel->max + 1)) - 1;
	sel->line = (sel->nb_file / (sel->col + 1)) - 1;
	if ((fd = open("/dev/tty", O_RDWR)) == -1)
		exit(EXIT_FAILURE);
	sel->fd = ft_get_fd(fd);
	if (sel->nb_file % (sel->col + 1) != 0)
		sel->line++;
	if ((sel->nb_file - 1) < sel->col)
		sel->col = sel->nb_file - 1;
}

void	ft_modif_struct(t_select *sel)
{
	ioctl(STDIN_FILENO, TIOCGWINSZ, &sel->win);
	sel->nb_file--;
	sel->max = ft_return_msd(sel->file);
	sel->col = (sel->win.ws_col / (sel->max + 1)) - 1;
	sel->line = (sel->nb_file / (sel->col + 1)) - 1;
	if (sel->nb_file % (sel->col + 1) != 0)
		sel->line++;
	if ((sel->nb_file - 1) < sel->col)
		sel->col = sel->nb_file - 1;
}
