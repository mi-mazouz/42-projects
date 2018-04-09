/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:12:49 by MrRobot           #+#    #+#             */
/*   Updated: 2016/08/30 18:44:50 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_put(int c)
{
	ft_putchar_fd(c, g_shell.fd.fd);
	return (0);
}

void	ft_put_curs(t_line *line)
{
	if (line->curs->next != NULL)
		line->curs = line->curs->next;
	ft_putchar_fd(((t_char *)line->curs->data)->c, g_shell.fd.stdout);
	line->left = 0;
}

int		ft_put_line(t_list *curs)
{
	struct winsize	win;
	t_list			*ptr;
	int				col;
	int				row;
	int				row_2;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &win);
	ptr = curs;
	while (ptr != NULL)
	{
		if (ptr->next == NULL)
			row_2 = ft_curs_pos_row(g_shell.fd.fd);
		if ((((t_char *)ptr->data)->under) == 1)
			tputs(tgetstr("mr", NULL), 0, ft_put);
		ft_putchar_fd(((t_char *)ptr->data)->c, g_shell.fd.stdout);
		tputs(tgetstr("me", NULL), 0, ft_put);
		ptr = ptr->next;
	}
	row = ft_curs_pos_row(g_shell.fd.fd);
	col = ft_curs_pos_col(g_shell.fd.fd);
	if (col == 2 && row == win.ws_row && row_2 == win.ws_row)
		return (2);
	return (1);
}

void	ft_print_prompt(int test)
{
	if (test == 1)
	{
		ft_putchar_fd('\n', g_shell.fd.fd);
		tputs(tgetstr("cd", NULL), 0, ft_put);
	}
	ft_putstr_fd(RED, g_shell.fd.fd);
	ft_putstr_fd("Mr.Robot", g_shell.fd.fd);
	ft_putstr_fd(BLUE, g_shell.fd.fd);
	ft_putstr_fd("--> ", g_shell.fd.fd);
	ft_putstr_fd(STOP, g_shell.fd.fd);
}
