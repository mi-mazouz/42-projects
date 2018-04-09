/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 16:59:23 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/13 19:28:22 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_echo(char **tab)
{
	int		i;

	i = 1;
	if (tab[i] != NULL && ft_strcmp(tab[i], "-n") == 0)
		i++;
	while (tab[i] != NULL)
	{
		ft_putstr_fd(tab[i], g_shell.fd.stdout);
		i++;
		if (tab[i] != NULL)
			ft_putchar_fd(' ', g_shell.fd.stdout);
	}
	if (tab[1] == NULL || ft_strcmp(tab[1], "-n") != 0)
		ft_putchar_fd('\n', g_shell.fd.stdout);
}
