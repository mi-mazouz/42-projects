/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 19:26:30 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/03 16:06:42 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_select(t_select *sel)
{
	if (((t_file *)sel->curs->data)->select == 1)
	{
		((t_file *)sel->curs->data)->select = 0;
		ft_put_file(sel, 1);
		ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
		return ;
	}
	ft_put_file(sel, 0);
	if (sel->curs->next == NULL)
		ft_select_first(sel);
	else if (sel->right == sel->col)
		ft_select_bottom(sel);
	else
	{
		ft_put_curs(tgetstr("nd", NULL),
			(sel->max - ((t_file *)sel->curs->data)->size) + 1);
		((t_file *)sel->curs->data)->select = 1;
		sel->curs = sel->curs->next;
		ft_put_file(sel, 1);
		ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
		sel->right++;
		sel->left++;
	}
}

void	ft_select_bottom(t_select *sel)
{
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	tputs(tgetstr("do", NULL), 0, ft_puts);
	((t_file *)sel->curs->data)->select = 1;
	sel->curs = sel->curs->next;
	ft_put_file(sel, 1);
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	sel->right = 0;
	sel->left = 0;
	sel->bot++;
	sel->top++;
	tputs(tgetstr("me", NULL), 0, ft_puts);
}

void	ft_select_first(t_select *sel)
{
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	((t_file *)sel->curs->data)->select = 1;
	ft_go_to_first(&sel->curs);
	tputs(tgetstr("rc", NULL), 0, ft_puts);
	ft_put_file(sel, 1);
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	sel->right = 0;
	sel->left = 0;
	sel->top = 0;
	sel->bot = 0;
}
