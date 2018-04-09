/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 11:34:54 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/13 12:07:18 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int power)
{
	int i;
	int res;

	i = 1;
	res = nb;
	while (i < power)
	{
		res = res * nb;
		i++;
	}
	return (res);
}
