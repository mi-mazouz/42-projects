/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 09:03:48 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/23 15:49:37 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_exit(struct termios *term_restore, int test)
{
	if (g_shell.line.start != NULL && test == 0)
		return ;
	tcsetattr(0, TCSADRAIN, term_restore);
	close(g_shell.fd.fd);
	exit(EXIT_SUCCESS);
}
