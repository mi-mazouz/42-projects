/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:53:07 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 15:54:53 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_bl(intmax_t n, unsigned int base)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n < base)
	{
		if (n < 10)
			ft_putchar(n + 48);
		else
			ft_putchar(n + 55);
	}
	else
	{
		ft_putnbr_bl(n / base, base);
		if (n % base < 10)
			ft_putchar(n % base + 48);
		else
			ft_putchar(n % base + 55);
	}
}
