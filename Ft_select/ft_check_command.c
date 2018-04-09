/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 17:47:28 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/09 09:13:15 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_check_cmd(t_select *sel)
{
	t_list	*ptr;

	ptr = sel->curs;
	if (sel->buf[0] == 27 && sel->buf[1] == 91 && sel->buf[2] == 67)
		ft_right(sel);
	else if (sel->buf[0] == 27 && sel->buf[1] == 91 && sel->buf[2] == 68)
		ft_left(sel);
	else if (sel->buf[0] == 27 && sel->buf[1] == 91 && sel->buf[2] == 65 &&
		sel->nb_file > (sel->col + 1))
		ft_top(sel, ptr);
	else if (sel->buf[0] == 27 && sel->buf[1] == 91 && sel->buf[2] == 66 &&
		sel->nb_file > (sel->col + 1))
		ft_bottom(sel);
	else if (sel->buf[0] == 32 && sel->buf[1] == 0 && sel->buf[2] == 0)
		ft_select(sel);
	else if (sel->buf[0] == 10 && sel->buf[1] == 0)
		ft_return(sel);
	else if ((sel->buf[0] == 127 && sel->buf[1] == 0) ||
		(sel->buf[0] == 27 && sel->buf[1] == 91 && sel->buf[2] == 51))
		ft_delete(sel);
}
