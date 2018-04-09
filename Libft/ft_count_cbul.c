/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_cbul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:05:41 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 15:58:01 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t		ft_count_cbul(uintmax_t n, unsigned int base)
{
	uintmax_t	c;

	c = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		c++;
	}
	return (c);
}
