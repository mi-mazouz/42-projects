/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 17:27:02 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/09 09:22:44 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_ctrlz(t_select *sel)
{
	char		c[2];

	signal(SIGTSTP, SIG_DFL);
	tputs(tgetstr("rc", NULL), 0, ft_puts);
	tputs(tgetstr("cd", NULL), 0, ft_puts);
	c[0] = sel->term_restore.c_cc[VSUSP];
	c[1] = '\0';
	ioctl(0, TIOCSTI, c);
	ft_reset_term(sel);
}

void	ft_signal_finish(int signal)
{
	t_select	*sel;

	sel = ft_get_struct(NULL);
	if (signal == 28)
	{
		ioctl(STDIN_FILENO, TIOCGWINSZ, &sel->win);
		ft_get_new_win_size(sel);
	}
	else if (signal == 18)
		ft_ctrlz(sel);
	else if (signal == 19)
	{
		ft_signal();
		ioctl(STDIN_FILENO, TIOCGWINSZ, &sel->win);
		ft_modif_term(sel);
		ft_get_new_win_size(sel);
	}
	else
		ft_esc(sel);
}

void	ft_signal(void)
{
	int	num;

	num = 1;
	while (num <= 31)
	{
		signal(num, &ft_signal_finish);
		num++;
	}
}
