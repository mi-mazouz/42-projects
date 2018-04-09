/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:52:42 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 15:20:15 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_bl(intmax_t n, unsigned int base)
{
	intmax_t		c;
	char			*res;

	c = ft_count_cbl(n, base);
	if (!(res = ft_strnew(c)))
		return (NULL);
	if (n == 0)
		return ("0");
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	while (n > 0)
	{
		c--;
		if (n % base < 10)
			res[c] = n % base + 48;
		else
			res[c] = n % base + 55;
		n = n / base;
	}
	return (res);
}
