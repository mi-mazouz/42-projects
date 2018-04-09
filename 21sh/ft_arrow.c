/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 10:14:32 by MrRobot           #+#    #+#             */
/*   Updated: 2016/06/14 20:33:37 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_right(t_line *line)
{
	int	col;
	int	row;

	if (line->curs == NULL)
		return ;
	if (line->left == 1 && line->curs->prev == NULL)
	{
		tputs(tgetstr("nd", NULL), 0, ft_put);
		line->left = 0;
	}
	else if (line->curs->next != NULL)
	{
		col = ft_curs_pos_col(g_shell.fd.fd);
		row = ft_curs_pos_row(g_shell.fd.fd);
		if (col == line->win.ws_col)
			tputs(tgoto(tgetstr("cm", NULL), 0, row), 0, ft_put);
		else
			tputs(tgetstr("nd", NULL), 0, ft_put);
		line->curs = line->curs->next;
	}
}

void	ft_left(t_line *line)
{
	int				col;
	int				row;
	char			*str;

	if (line->curs == NULL)
		return ;
	if (line->left == 0 && line->curs->prev == NULL)
	{
		tputs(tgetstr("le", NULL), 0, ft_put);
		line->left = 1;
	}
	else if (line->curs->prev != NULL)
	{
		col = ft_curs_pos_col(g_shell.fd.fd);
		row = ft_curs_pos_row(g_shell.fd.fd);
		str = tgetstr("cm", NULL);
		if (col == 1)
			tputs(tgoto(str, line->win.ws_col, row - 2), 0, ft_put);
		else
			tputs(tgetstr("le", NULL), 0, ft_put);
		line->curs = line->curs->prev;
	}
}
