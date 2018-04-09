/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 15:43:30 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/20 17:33:08 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char **argv)
{
	t_lemin	lemin;
	char	**path;

	ft_init_struct(&lemin);
	ft_check_option(&lemin, argv, argc);
	ft_treat_data(&lemin);
	if (lemin.room.room == 0 || lemin.pipe.pipe == 0)
	{
		ft_putendl("ERROR");
		return (0);
	}
	else if ((path = ft_treat_algo(&lemin.pipe, &lemin.room)) == NULL)
	{
		ft_putendl("ERROR");
		return (0);
	}
	if (lemin.h == 0)
		ft_print_file(lemin.file.start);
	ft_print_ant_course(path, &lemin);
	ft_free_tab(path);
	return (1);
}
