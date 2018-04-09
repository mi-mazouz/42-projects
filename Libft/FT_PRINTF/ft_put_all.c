/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:59:52 by mimazouz          #+#    #+#             */
/*   Updated: 2016/03/31 16:22:00 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_unsigned_long(unsigned long n, unsigned int base)
{
	if (n < base)
	{
		if (n < 10)
			ft_putchar(n + 48);
		else
			ft_putchar(n + 87);
	}
	else
	{
		ft_putnbr_base_unsigned_long(n / base, base);
		if (n % base < 10)
			ft_putchar(n % base + 48);
		else
			ft_putchar(n % base + 87);
	}
}

void	ft_putint(int c)
{
	write(1, &c, 1);
}
