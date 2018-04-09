/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 19:25:11 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/29 14:39:45 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_read_key(t_select *sel)
{
	ft_put_curs(tgetstr("do", NULL), sel->line);
	ft_put_curs(tgetstr("up", NULL), sel->line);
	tputs(tgetstr("sc", NULL), 0, ft_puts);
	ft_signal();
	while (sel->line >= sel->win.ws_row)
	{
		tputs(tgetstr("rc", NULL), 0, ft_puts);
		ft_putstr_fd("ERROR\n", sel->fd);
		ft_strclr(sel->buf, 4);
		read(0, sel->buf, 3);
		if (sel->buf[0] == 27 && sel->buf[1] == 0)
			ft_esc(sel);
	}
	ft_print_list(sel->file, sel, -2);
	tputs(tgetstr("rc", NULL), 0, ft_puts);
	ft_strclr(sel->buf, 4);
	while (read(0, sel->buf, 3))
	{
		if (sel->buf[0] == 27 && sel->buf[1] == 0)
			ft_esc(sel);
		else if (sel->lev == 0)
			ft_check_cmd(sel);
		ft_strclr(sel->buf, 4);
	}
}
