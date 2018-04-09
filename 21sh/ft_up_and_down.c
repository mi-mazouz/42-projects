/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_and_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 10:14:13 by MrRobot           #+#    #+#             */
/*   Updated: 2016/08/29 11:23:24 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	ft_check_up_or_down(t_line *line, int test)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = line->curs;
	while (ptr != NULL)
	{
		if (test == 0)
			ptr = ptr->prev;
		else
		{
			if (ptr->next == NULL)
				break ;
			ptr = ptr->next;
		}
		i++;
	}
	if (i < line->win.ws_col)
		return (-1);
	return (1);
}

void		ft_down(t_line *line)
{
	int	i;
	int	col;
	int	j;

	if (line->start == NULL || (ft_check_up_or_down(line, 1) == -1))
		return ;
	i = line->win.ws_col;
	if (line->left == 1)
		i -= 1;
	j = 1;
	col = ft_curs_pos_col(g_shell.fd.fd);
	tputs(tgetstr("do", NULL), 0, ft_put);
	while (j < col)
	{
		tputs(tgetstr("nd", NULL), 0, ft_put);
		j++;
	}
	while (i-- > 0)
		line->curs = line->curs->next;
	line->left = 0;
}

void		ft_up(t_line *line)
{
	int	i;

	if (line->start == NULL || (ft_check_up_or_down(line, 0) == -1))
		return ;
	i = line->win.ws_col;
	tputs(tgetstr("up", NULL), 0, ft_put);
	while (i > 0)
	{
		if (line->curs->prev == NULL)
		{
			if (i == 1)
				line->left = 1;
			break ;
		}
		line->curs = line->curs->prev;
		i--;
	}
}
