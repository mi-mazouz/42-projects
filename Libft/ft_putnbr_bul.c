/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:32:54 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 15:54:40 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_bul(uintmax_t n, unsigned int base)
{
	if (n < base)
	{
		if (n < 10)
			ft_putchar(n + 48);
		else
			ft_putchar(n + 55);
	}
	else
	{
		ft_putnbr_bul(n / base, base);
		if (n % base < 10)
			ft_putchar(n % base + 48);
		else
			ft_putchar(n % base + 55);
	}
}
