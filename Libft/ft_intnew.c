/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 12:26:12 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/22 12:33:21 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intnew(size_t n)
{
	size_t	i;
	int		*new;

	i = 0;
	new = (int *)malloc(sizeof(int) * n);
	while (i < n)
	{
		new[i] = -1;
		i++;
	}
	return (new);
}
