/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 13:36:06 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 19:32:59 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_fill_option(t_flags *flags, char **argv, int i, int *j)
{
	if (argv[i][*j] == '-' && argv[i][*j + 1] == '-')
	{
		flags->road = 1;
		return (1);
	}
	if (argv[i][*j] == '-' && flags->option == 0)
		(*j)++;
	flags->option = 1;
	if (argv[i][*j] == 'l')
		flags->l = 1;
	else if (argv[i][*j] == 'R')
		flags->gr = 1;
	else if (argv[i][*j] == 'a')
		flags->a = 1;
	else if (argv[i][*j] == 't')
		flags->t = 1;
	else if (argv[i][*j] == 'f')
		flags->f = 1;
	else if (argv[i][*j] == 'r')
		flags->r = 1;
	else
		return (0);
	return (1);
}
