/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:48:40 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/01 18:52:20 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnchar_fd(char c, size_t size, int fd)
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
	write(fd, str, size);
}
