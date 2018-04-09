/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 13:46:09 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 19:33:02 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_read_argv(t_flags *flags, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < flags->argc && flags->road == 0)
	{
		j = 0;
		flags->option = 0;
		while (argv[i][j] != 0)
		{
			if ((argv[i][j] == '-' || flags->option == 1) && flags->road == 0)
			{
				if (ft_fill_option(flags, argv, i, &j) == 0)
					return (ft_error(argv[i][j]));
				j++;
			}
			else
			{
				ft_treat_path(flags, argv, i);
				break ;
			}
		}
		i++;
	}
	return (0);
}
