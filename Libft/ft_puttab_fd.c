/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:47:09 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/16 13:49:41 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab_fd(char **tab, char c, int fd)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr_fd(tab[i], fd);
		if (tab[i + 1] != NULL)
			ft_putchar_fd(c, fd);
		i++;
	}
}
