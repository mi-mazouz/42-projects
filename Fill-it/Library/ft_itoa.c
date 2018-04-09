/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:09:21 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/10 12:07:59 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		c;
	int		n_save;
	char	*res;

	c = ft_count_case(n);
	n_save = n;
	if (n <= 0)
		n = -n;
	res = ft_strnew(c);
	if (!res)
		return (NULL);
	if (n_save == 0 || n_save == -0)
		return (ft_strcpy(res, "0"));
	if (n_save == -2147483648)
		return (ft_strcpy(res, "-2147483648"));
	while (c + 2 > 0)
	{
		c--;
		res[c] = (n % 10) + 48;
		n = n / 10;
	}
	if (n_save < 0)
		res[0] = '-';
	return (res);
}
