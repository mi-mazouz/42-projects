/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 19:20:55 by MrRobot           #+#    #+#             */
/*   Updated: 2016/06/02 18:04:13 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		ft_modif_term(struct termios *term_set, int test)
{
	tcgetattr(0, term_set);
	if (test == 0)
		term_set->c_lflag &= ~(ICANON | ECHO);
	else if (test == 1)
		term_set->c_lflag &= ~(ICANON | ECHO | CREAD);
	tcsetattr(0, TCSANOW, term_set);
}
