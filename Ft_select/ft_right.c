/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:59:20 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/03 15:55:25 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_right(t_select *sel)
{
	ft_put_file(sel, 0);
	if (sel->curs->next == NULL)
		ft_right_first(sel);
	else if (sel->right == sel->col)
		ft_right_bottom(sel);
	else
	{
		ft_put_curs(tgetstr("nd", NULL),
			(sel->max - ((t_file *)sel->curs->data)->size) + 1);
		sel->curs = sel->curs->next;
		ft_put_file(sel, 1);
		ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
		sel->left++;
		sel->right++;
	}
}

void	ft_right_first(t_select *sel)
{
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	ft_go_to_first(&sel->curs);
	tputs(tgetstr("rc", NULL), 0, ft_puts);
	ft_put_file(sel, 1);
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	sel->left = 0;
	sel->right = 0;
	sel->top = 0;
	sel->bot = 0;
}

void	ft_right_bottom(t_select *sel)
{
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	tputs(tgetstr("do", NULL), 0, ft_puts);
	sel->curs = sel->curs->next;
	ft_put_file(sel, 1);
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	sel->left = 0;
	sel->right = 0;
	sel->top++;
	sel->bot++;
}
