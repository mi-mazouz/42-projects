/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_21sh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:06:42 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/07 20:05:12 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_21sh(t_shell *shell)
{
	char	buf[7];

	ft_strclr(buf, 7);
	signal(SIGINT, ft_signal);
	while (read(0, buf, 6) > 0)
	{
		if (ft_isprint(buf[0]) != 1)
			ft_check_touch(&shell->line, &shell->his, buf);
		else
		{
			ft_line_in_list(&shell->line, buf[0]);
			if (shell->line.curs->next == NULL)
				ft_put_curs(&shell->line);
			else
				ft_insert_char(&shell->line);
		}
		signal(SIGINT, ft_signal);
		ft_strclr(buf, 7);
	}
}
