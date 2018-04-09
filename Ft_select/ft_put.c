/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 18:27:30 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/03 17:49:53 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_puts(int c)
{
	int	fd;

	fd = ft_get_fd(-1);
	ft_putchar_fd(c, fd);
	return (0);
}

void	ft_put_file(t_select *sel, int underline)
{
	if (underline == 1)
		tputs(tgetstr("us", NULL), 0, ft_puts);
	if (((t_file *)sel->curs->data)->select == 1 || (sel->buf[0] == ' ' &&
		sel->buf[1] == 0 && ((t_file *)sel->curs->data)->select == 0 &&
			underline == 0))
		tputs(tgetstr("mr", NULL), 0, ft_puts);
	ft_putstr_fd(((t_file *)sel->curs->data)->name, sel->fd);
	tputs(tgetstr("ue", NULL), 0, ft_puts);
	tputs(tgetstr("me", NULL), 0, ft_puts);
}

void	ft_put_curs(char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		tputs(str, 0, ft_puts);
		i++;
	}
}
