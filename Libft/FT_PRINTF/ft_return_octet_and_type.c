/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_octet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:26:38 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/01 19:40:35 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_return_octet(int p)
{
	char	*str;
	int		i;
	int		len;

	i = 31;
	str = (char *)malloc(sizeof(char) * 33);
	ft_strclr(str, 33);
	while (p > 0)
	{
		str[i] = (p % 2) + 48;
		p = p / 2;
		i--;
	}
	len = ft_nb_octet(str);
	free(str);
	if (len <= 7)
		return (1);
	else if (len <= 11)
		return (2);
	else if (len <= 16)
		return (3);
	return (4);
}

unsigned long	ft_return_type_u(t_printf *link, va_list ap)
{
	unsigned long p;

	if (link->l == 1 || link->l == 2 || link->letter == 'U' ||
			link->letter == 'O')
		p = va_arg(ap, unsigned long);
	else if (link->j == 1)
		p = va_arg(ap, uintmax_t);
	else if (link->h == 2)
		p = (unsigned char)va_arg(ap, unsigned int);
	else if (link->h == 1)
		p = (unsigned short)va_arg(ap, unsigned int);
	else if (link->z == 1)
		p = va_arg(ap, size_t);
	else
		p = va_arg(ap, unsigned int);
	return (p);
}

long			ft_return_type(t_printf *link, va_list ap)
{
	long p;

	if (link->l == 1 || link->l == 2 || link->letter == 'D')
		p = va_arg(ap, long);
	else if (link->j == 1)
		p = va_arg(ap, intmax_t);
	else if (link->h == 2)
		p = (char)va_arg(ap, int);
	else if (link->h == 1)
		p = (short)va_arg(ap, int);
	else if (link->z == 1)
		p = va_arg(ap, size_t);
	else
		p = va_arg(ap, int);
	return (p);
}
