/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:29:32 by MrRobot           #+#    #+#             */
/*   Updated: 2016/06/02 18:16:08 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signal(int sig)
{
	sig = 0;
	ft_printf("\n%sMr.Robot%s--> %s", RED, BLUE, STOP);
}

void	ft_signal_2(int sig)
{
	sig = 0;
	ft_putchar('\n');
}
