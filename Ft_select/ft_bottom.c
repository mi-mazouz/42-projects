/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bottom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 18:08:08 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/03 15:56:51 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_bottom(t_select *sel)
{
	size_t	i;

	if (sel->bot != sel->line && sel->curs->next != NULL &&
		(((t_file *)sel->curs->data)->pos + (sel->col + 1)) >= sel->nb_file)
		return ;
	ft_put_file(sel, 0);
	if (sel->curs->next == NULL)
		ft_right_first(sel);
	else if (sel->bot == sel->line)
		ft_bottom_top(sel);
	else
	{
		i = 0;
		ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
		tputs(tgetstr("do", NULL), 0, ft_puts);
		while (i++ < ((t_file *)sel->curs->data)->pos % (sel->col + 1))
			ft_put_curs(tgetstr("nd", NULL), sel->max + 1);
		i = 0;
		while (i++ < (sel->col + 1))
			sel->curs = sel->curs->next;
		ft_put_file(sel, 1);
		ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
		sel->top++;
		sel->bot++;
	}
}

void	ft_bottom_top(t_select *sel)
{
	size_t	i;
	size_t	col;

	i = 0;
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	tputs(tgetstr("rc", NULL), 0, ft_puts);
	col = ((t_file *)sel->curs->data)->pos % (sel->col + 1);
	ft_go_to_first(&sel->curs);
	while (i++ <= col)
	{
		sel->curs = sel->curs->next;
		ft_put_curs(tgetstr("nd", NULL), (sel->max + 1));
	}
	ft_put_file(sel, 1);
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	sel->right = ((t_file *)sel->curs->data)->pos % (sel->col + 1);
	sel->left = ((t_file *)sel->curs->data)->pos % (sel->col + 1);
	sel->top = 0;
	sel->bot = 0;
}
