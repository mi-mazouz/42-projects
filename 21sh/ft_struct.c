/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:02:07 by MrRobot           #+#    #+#             */
/*   Updated: 2016/08/31 10:35:41 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_init_new_line(t_line *new_line)
{
	new_line->cmd = NULL;
	new_line->start = NULL;
	new_line->curs = NULL;
	new_line->copy.curs = NULL;
	new_line->copy.start = NULL;
	new_line->left = 0;
}

void	ft_init_struct(t_shell *shell)
{
	ioctl(STDIN_FILENO, TIOCGWINSZ, &shell->line.win);
	shell->fd.stdin = 0;
	shell->fd.stdout = 1;
	shell->fd.stderr = 2;
	shell->fd.fd = open("/dev/tty", O_RDWR);
	ft_init_new_line(&shell->line);
	shell->his.start = NULL;
	shell->his.left = 0;
	shell->his.go = 0;
	shell->his.curs = NULL;
	shell->tab.path = NULL;
	shell->tab.file = NULL;
	shell->tab.abrvt = NULL;
}
