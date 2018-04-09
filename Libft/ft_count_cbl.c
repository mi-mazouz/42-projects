/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_cbl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:51:49 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 15:08:42 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t		ft_count_cbl(intmax_t n, unsigned int base)
{
	intmax_t	c;

	c = 0;
	if (n < 0)
	{
		n = -n;
		c++;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		c++;
	}
	return (c);
}
