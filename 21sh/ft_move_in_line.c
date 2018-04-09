/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deplace_in_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 12:28:52 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/01 19:30:51 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_home(t_line *line)
{
	int	col;
	int row;
	int	ws_col;

	if (line->start == NULL || line->left == 1)
		return ;
	while (line->curs->prev != NULL)
	{
		col = ft_curs_pos_col(g_shell.fd.fd);
		if (col == 1)
		{
			row = ft_curs_pos_row(g_shell.fd.fd);
			ws_col = line->win.ws_col;
			tputs(tgoto(tgetstr("cm", NULL), ws_col, row - 2), 0, ft_put);
		}
		else
			tputs(tgetstr("le", NULL), 0, ft_put);
		line->curs = line->curs->prev;
	}
	tputs(tgetstr("le", NULL), 0, ft_put);
	line->left = 1;
}

void	ft_end(t_line *line)
{
	int		col;

	if (line->curs == NULL)
		return ;
	while (line->curs->next != NULL)
	{
		col = ft_curs_pos_col(g_shell.fd.fd);
		if (col == line->win.ws_col)
			tputs(tgetstr("do", NULL), 0, ft_put);
		else
			tputs(tgetstr("nd", NULL), 0, ft_put);
		line->curs = line->curs->next;
	}
	if (line->left == 1)
	{
		tputs(tgetstr("nd", NULL), 0, ft_put);
		line->left = 0;
	}
}

void	ft_word_right(t_line *line)
{
	int	col;
	int	sp;

	sp = 0;
	while (line->start != NULL && line->curs->next != NULL)
	{
		if (line->left == 1)
		{
			tputs(tgetstr("nd", NULL), 0, ft_put);
			line->left = 0;
		}
		if (sp == 1 && ft_isspace(((t_char *)line->curs->next->data)->c) != 1)
			return ;
		if (ft_isspace(((t_char *)line->curs->next->data)->c) == 1)
			sp = 1;
		col = ft_curs_pos_col(g_shell.fd.fd);
		if (col == line->win.ws_col)
			tputs(tgetstr("do", NULL), 0, ft_put);
		else
			tputs(tgetstr("nd", NULL), 0, ft_put);
		line->curs = line->curs->next;
	}
}

void	ft_word_left(t_line *line)
{
	int lt;

	lt = 0;
	while (line->start != NULL && line->curs->prev != NULL)
	{
		if (lt == 1 && ft_isspace(((t_char *)line->curs->data)->c) == 1)
			return ;
		else if (ft_isspace(((t_char *)line->curs->data)->c) != 1)
			lt = 1;
		tputs(tgetstr("le", NULL), 0, ft_put);
		line->curs = line->curs->prev;
		if (line->curs->prev == NULL)
		{
			tputs(tgetstr("le", NULL), 0, ft_put);
			line->left = 1;
		}
	}
	if (line->left == 0)
	{
		tputs(tgetstr("le", NULL), 0, ft_put);
		line->left = 1;
	}
}
