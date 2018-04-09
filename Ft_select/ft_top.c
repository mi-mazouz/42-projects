/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 12:59:01 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/05 12:50:37 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_top(t_select *sel, t_list *ptr)
{
	size_t	i;

	ft_go_to_last(&ptr);
	i = 0;
	if (sel->top == 0 && sel->curs->prev != NULL &&
		((((t_file *)ptr->data)->pos % (sel->col + 1)) <
			((((t_file *)sel->curs->data)->pos % (sel->col + 1)) - 1)))
		return ;
	ft_put_file(sel, 0);
	if (sel->curs->prev == NULL)
		ft_left_last(sel);
	else if (sel->top == 0)
		ft_top_bottom(sel);
	else
	{
		ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
		tputs(tgetstr("up", NULL), 0, ft_puts);
		while (i++ < (sel->col + 1))
			sel->curs = sel->curs->prev;
		ft_put_file(sel, 1);
		ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
		sel->top--;
		sel->bot--;
	}
}

void	ft_top_bottom(t_select *sel)
{
	size_t	i;
	size_t	col;

	i = 0;
	col = ((t_file *)sel->curs->data)->pos % (sel->col + 1);
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	ft_go_to_last(&sel->curs);
	ft_put_curs(tgetstr("do", NULL), sel->line);
	while ((((t_file *)sel->curs->data)->pos % (sel->col + 1)) > col - 1)
		sel->curs = sel->curs->prev;
	while (i++ < col - 1)
		ft_put_curs(tgetstr("nd", NULL), (sel->max + 1));
	ft_put_file(sel, 1);
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	sel->bot = sel->line;
	sel->top = sel->line;
	sel->left = ((t_file *)sel->curs->data)->pos % (sel->col + 1);
	sel->right = ((t_file *)sel->curs->data)->pos % (sel->col + 1);
}
