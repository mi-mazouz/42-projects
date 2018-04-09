/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:17:18 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/03 15:54:53 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_left(t_select *sel)
{
	ft_put_file(sel, 0);
	if (sel->curs->prev == NULL)
		ft_left_last(sel);
	else if (sel->left == 0)
		ft_left_top(sel);
	else
	{
		ft_put_curs(tgetstr("le", NULL),
			(sel->max + ((t_file *)sel->curs->data)->size) + 1);
		sel->curs = sel->curs->prev;
		ft_put_file(sel, 1);
		ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
		sel->left--;
		sel->right--;
	}
}

void	ft_left_last(t_select *sel)
{
	size_t	i;

	i = 0;
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	ft_go_to_last(&sel->curs);
	ft_put_curs(tgetstr("do", NULL), sel->line);
	while (i++ < ((t_file *)sel->curs->data)->pos % (sel->col + 1))
		ft_put_curs(tgetstr("nd", NULL), (sel->max + 1));
	ft_put_file(sel, 1);
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	sel->bot = sel->line;
	sel->top = sel->line;
	sel->right = ((t_file *)sel->curs->data)->pos % (sel->col + 1);
	sel->left = ((t_file *)sel->curs->data)->pos % (sel->col + 1);
}

void	ft_left_top(t_select *sel)
{
	size_t	i;

	i = 0;
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	sel->curs = sel->curs->prev;
	tputs(tgetstr("up", NULL), 0, ft_puts);
	while (i++ < sel->col)
		ft_put_curs(tgetstr("nd", NULL), (sel->max + 1));
	ft_put_file(sel, 1);
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	sel->right = sel->col;
	sel->left = sel->col;
	sel->top--;
	sel->bot--;
}
