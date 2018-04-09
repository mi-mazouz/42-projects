/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 09:34:53 by MrRobot           #+#    #+#             */
/*   Updated: 2016/06/14 20:38:37 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	ft_delete_residue(t_line *line)
{
	int		col;
	int		row;
	char	*str;

	col = ft_curs_pos_col(g_shell.fd.fd);
	row = ft_curs_pos_row(g_shell.fd.fd);
	str = tgetstr("cm", NULL);
	if (col == 1 && line->curs->next == NULL)
	{
		tputs(tgoto(str, line->win.ws_col, row - 2), 0, ft_put);
		tputs(tgetstr("dc", NULL), 0, ft_put);
	}
	else
	{
		if (col == 1)
			tputs(tgoto(str, line->win.ws_col, row - 2), 0, ft_put);
		else
			tputs(tgetstr("le", NULL), 0, ft_put);
		tputs(tgetstr("cd", NULL), 0, ft_put);
		col = ft_curs_pos_col(g_shell.fd.fd);
		row = ft_curs_pos_row(g_shell.fd.fd);
		ft_put_line(line->curs->next);
		tputs(tgoto(str, col - 1, row - 1), 0, ft_put);
	}
}

static void	ft_delete_first(t_line *line)
{
	int	col;
	int	row;

	tputs(tgetstr("le", NULL), 0, ft_put);
	tputs(tgetstr("cd", NULL), 0, ft_put);
	col = ft_curs_pos_col(g_shell.fd.fd);
	row = ft_curs_pos_row(g_shell.fd.fd);
	if (line->curs->next == NULL)
	{
		ft_list_del_last_one(&line->start, ft_free);
		line->left = 0;
		line->curs = NULL;
	}
	else
	{
		ft_list_del_first(&line->start, ft_free);
		line->left = 1;
		line->curs = line->start;
		ft_put_line(line->curs);
		tputs(tgoto(tgetstr("cm", NULL), col - 1, row - 1), 0, ft_put);
	}
}

void		ft_delete(t_line *line)
{
	if (line->curs == NULL || (line->left == 1 && line->curs->prev == NULL))
		return ;
	if (line->curs->prev == NULL)
		ft_delete_first(line);
	else
	{
		line->curs = line->curs->prev;
		if (line->curs->next->next != NULL)
			ft_list_del(line->curs->next, ft_free);
		else
			ft_list_del_last(&line->start, ft_free);
		ft_delete_residue(line);
	}
}
