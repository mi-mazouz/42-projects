/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 17:19:25 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/01 18:52:22 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnchar(char c, size_t size)
{
	char	str[size + 1];
	size_t	i;

	i = 0;
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	str[size] = 0;
	write(1, str, size);
}
