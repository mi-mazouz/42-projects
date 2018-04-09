/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 16:39:24 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/04 18:05:18 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_error(int error)
{
	if (error == 1)
		ft_putstr("No file declared !\n");
	else if (error == 2)
		ft_putstr("No name for the terminal\n");
	return (1);
}
