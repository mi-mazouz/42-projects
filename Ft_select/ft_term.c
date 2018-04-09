/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 19:20:55 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/09 09:21:34 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_modif_term(t_select *sel)
{
	tputs(tgetstr("vi", NULL), 0, ft_puts);
	sel->term_update.c_lflag &= ~(ICANON);
	sel->term_update.c_lflag &= ~(ECHO);
	if (tcsetattr(0, TCSADRAIN, &sel->term_update) == 1)
		exit(EXIT_FAILURE);
	sel = ft_get_struct(sel);
}

void		ft_reset_term(t_select *sel)
{
	tputs(tgetstr("ve", NULL), 0, ft_puts);
	if (tcsetattr(0, TCSADRAIN, &sel->term_restore) == 1)
		exit(EXIT_FAILURE);
}

int			ft_get_fd(int test)
{
	static int	fd;

	if (test < 0)
		return (fd);
	else
	{
		fd = test;
		return (fd);
	}
}

void		ft_get_new_win_size(t_select *sel)
{
	if (sel->win.ws_col > (sel->max + 1))
		sel->col = (sel->win.ws_col / (sel->max + 1)) - 1;
	sel->line = (sel->nb_file / (sel->col + 1)) - 1;
	if (sel->nb_file % (sel->col + 1) != 0)
		sel->line++;
	if ((sel->nb_file - 1) < sel->col)
		sel->col = sel->nb_file - 1;
	tputs(tgetstr("cl", NULL), 0, ft_puts);
	if (sel->line >= sel->win.ws_row || sel->max >= sel->win.ws_col)
	{
		ft_putstr_fd("ERROR", sel->fd);
		sel->lev = 1;
		return ;
	}
	((t_file *)sel->curs->data)->underline = 1;
	ft_print_list(sel->file, sel, -2);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 0, ft_puts);
	tputs(tgetstr("sc", NULL), 0, ft_puts);
	ft_deplace_curs(sel);
	sel->lev = 0;
	sel->right = ((t_file *)sel->curs->data)->pos % (sel->col + 1);
	sel->left = ((t_file *)sel->curs->data)->pos % (sel->col + 1);
	sel->top = ((t_file *)sel->curs->data)->pos / (sel->col + 1);
	sel->bot = ((t_file *)sel->curs->data)->pos / (sel->col + 1);
}

t_select	*ft_get_struct(t_select *sel)
{
	static t_select	*new_struct;

	if (sel != NULL)
	{
		new_struct = sel;
		return (new_struct);
	}
	else
		return (new_struct);
}
