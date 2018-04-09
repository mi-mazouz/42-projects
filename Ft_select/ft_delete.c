/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:38:32 by MrRobot           #+#    #+#             */
/*   Updated: 2016/06/20 10:40:56 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_delete(t_select *sel)
{
	t_list	*save;

	tputs(tgetstr("cd", NULL), 0, ft_puts);
	if (sel->curs->prev == NULL && sel->curs->next == NULL)
		ft_esc(sel);
	else if (((t_file *)sel->curs->data)->size == sel->max &&
			sel->curs->prev != NULL)
		ft_delete_max(sel);
	else if (sel->curs->next == NULL)
		ft_delete_last(sel);
	else if (sel->curs->prev == NULL)
		ft_delete_first(sel);
	else
	{
		save = sel->curs->next;
		ft_list_del(sel->curs, &ft_free_data);
		sel->curs = save;
		((t_file *)sel->curs->data)->underline = 1;
		ft_modif_pos(sel->curs);
		ft_modif_struct(sel);
		ft_print_list(sel->curs, sel, (sel->right - 2));
		tputs(tgetstr("rc", NULL), 0, ft_puts);
		ft_deplace_curs(sel);
	}
}

void	ft_delete_last(t_select *sel)
{
	t_list	*save;
	size_t	i;

	i = 0;
	save = sel->curs->prev;
	ft_list_del_last(&sel->curs, &ft_free_data);
	ft_put_curs(tgetstr("le", NULL), (sel->max + 1));
	sel->curs = save;
	ft_modif_struct(sel);
	if (sel->left == 0)
	{
		tputs(tgetstr("up", NULL), 0, ft_puts);
		while (i++ < sel->col)
			ft_put_curs(tgetstr("nd", NULL), (sel->max + 1));
		sel->top--;
		sel->bot--;
		sel->left = sel->col + 1;
		sel->right = sel->col + 1;
	}
	ft_put_file(sel, 1);
	ft_put_curs(tgetstr("le", NULL), ((t_file *)sel->curs->data)->size);
	sel->left--;
	sel->right--;
}

void	ft_delete_first(t_select *sel)
{
	t_list	*save;

	save = sel->curs->next;
	ft_list_del_first(&sel->curs, &ft_free_data);
	sel->curs = save;
	sel->file = sel->curs;
	ft_modif_pos(sel->curs);
	ft_modif_struct(sel);
	((t_file *)sel->curs->data)->underline = 1;
	ft_print_list(sel->curs, sel, -2);
	tputs(tgetstr("rc", NULL), 0, ft_puts);
	ft_deplace_curs(sel);
	sel->left = 0;
	sel->right = 0;
	sel->top = 0;
	sel->bot = 0;
}

void	ft_delete_max(t_select *sel)
{
	t_list	*save;

	tputs(tgetstr("rc", NULL), 0, ft_puts);
	tputs(tgetstr("cd", NULL), 0, ft_puts);
	if (sel->curs->next == NULL)
	{
		save = sel->curs->prev;
		ft_list_del_last(&sel->curs, &ft_free_data);
	}
	else
	{
		save = sel->curs->next;
		ft_list_del(sel->curs, &ft_free_data);
		ft_modif_pos(save);
	}
	sel->curs = save;
	((t_file *)sel->curs->data)->underline = 1;
	ft_modif_struct(sel);
	ft_print_list(sel->file, sel, -2);
	tputs(tgetstr("rc", NULL), 0, ft_puts);
	ft_deplace_curs(sel);
	sel->left = ((t_file *)sel->curs->data)->pos % (sel->col + 1);
	sel->right = ((t_file *)sel->curs->data)->pos % (sel->col + 1);
	sel->top = ((t_file *)sel->curs->data)->pos / (sel->col + 1);
	sel->bot = ((t_file *)sel->curs->data)->pos / (sel->col + 1);
}

void	ft_deplace_curs(t_select *sel)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ((t_file *)sel->curs->data)->pos / (sel->col + 1);
	ft_put_curs(tgetstr("do", NULL), i);
	i = ((t_file *)sel->curs->data)->pos % (sel->col + 1);
	while (j++ < i)
		ft_put_curs(tgetstr("nd", NULL), (sel->max + 1));
}
