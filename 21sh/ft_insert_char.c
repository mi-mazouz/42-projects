/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:14:38 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/01 14:58:52 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_insert_char(t_line *line)
{
	int		col;
	int		row;
	int		i;

	col = ft_curs_pos_col(g_shell.fd.fd);
	row = ft_curs_pos_row(g_shell.fd.fd);
	tputs(tgetstr("sc", NULL), 0, ft_put);
	tputs(tgetstr("cd", NULL), 0, ft_put);
	i = ft_put_line(line->curs);
	if (i == 2)
		tputs(tgoto(tgetstr("cm", NULL), col, row - i), 0, ft_put);
	else
	{
		tputs(tgetstr("rc", NULL), 0, ft_put);
		tputs(tgetstr("nd", NULL), 0, ft_put);
	}
	if (col == line->win.ws_col)
		tputs(tgetstr("do", NULL), 0, ft_put);
	line->left = 0;
	return ;
}
