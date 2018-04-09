/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 12:17:02 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 16:25:16 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_flags flags;

	ft_initialise_struct(&flags, argc);
	ft_no_path(argc, argv);
	if (ft_read_argv(&flags, argv) > 0)
		return (1);
	else if (argc == 1 || flags.road < 3)
		ft_one_path(&flags);
	return (0);
}
