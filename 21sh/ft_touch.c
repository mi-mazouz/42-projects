/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:26:29 by MrRobot           #+#    #+#             */
/*   Updated: 2016/08/29 15:00:19 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	ft_check_touch_2(t_line *line, t_his *his, char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
		ft_history_bottom(his, line);
	else if (buf[0] == 127 || (buf[0] == 27 && buf[1] == 91 && buf[2] == 51))
		ft_delete(line);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 70)
		ft_end(line);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 72)
		ft_home(line);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[5] == 68)
		ft_word_left(line);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[5] == 67)
		ft_word_right(line);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[5] == 65)
		ft_up(line);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[5] == 66)
		ft_down(line);
	else if (buf[0] == 27 && buf[1] == 27 && buf[2] == 91 && buf[3] == 67)
		ft_select_in_line(line);
	else if (buf[0] == -61 && buf[1] == -89)
		ft_copy_select(line);
	else if (buf[0] == -30 && buf[1] == -120 && buf[2] == -102)
		ft_cut_select(line);
	else if (buf[0] == -49 && buf[1] == -128)
		ft_paste_copy(line);
}

void		ft_check_touch(t_line *line, t_his *his, char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67)
		ft_right(line);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
		ft_left(line);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
		ft_history_top(his, line);
	else if (buf[0] == 4 && buf[1] == 0)
		ft_exit(&g_shell.term_restore, 0);
	else if (buf[0] == 10 && buf[1] == 0)
		ft_return(line, his, &g_shell.env);
	else if (buf[0] == 9 && buf[1] == 0)
		ft_tabulation(line, &g_shell.tab);
	else
		ft_check_touch_2(line, his, buf);
}
