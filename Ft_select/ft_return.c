/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:01:58 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/03 19:44:55 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_return(t_select *sel)
{
	size_t	size;

	size = 0;
	tputs(tgetstr("rc", NULL), 0, ft_puts);
	tputs(tgetstr("cd", NULL), 0, ft_puts);
	while (sel->file != NULL)
	{
		if (((t_file *)sel->file->data)->select == 1)
		{
			if ((size + ((t_file *)sel->file->data)->size) >= sel->win.ws_col)
			{
				ft_putchar('\n');
				size = 0;
			}
			size = (size + ((t_file *)sel->file->data)->size) + 1;
			ft_putstr(((t_file *)sel->file->data)->name);
			ft_putchar(' ');
		}
		sel->file = sel->file->next;
	}
	if (size != 0)
		ft_putchar_fd('\n', 1);
	ft_reset_term(sel);
	exit(EXIT_SUCCESS);
}

void	ft_esc(t_select *sel)
{
	tputs(tgetstr("rc", NULL), 0, ft_puts);
	tputs(tgetstr("cd", NULL), 0, ft_puts);
	ft_reset_term(sel);
	exit(EXIT_SUCCESS);
}
