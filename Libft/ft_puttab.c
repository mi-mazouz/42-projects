/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:45:02 by mimazouz          #+#    #+#             */
/*   Updated: 2016/09/19 17:02:36 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **tab, char c)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		if (tab[i + 1] != NULL)
			ft_putchar(c);
		i++;
	}
}
