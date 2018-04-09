/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fake_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 15:53:01 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 19:51:24 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_check_fake_path(t_flags *flags, char **argv, int i)
{
	struct stat	stats;
	int			p;

	p = 0;
	while (i < flags->argc)
	{
		if ((ft_strcmp(argv[i], "--") == 0) && p == 0)
		{
			p = 1;
			i++;
			continue ;
		}
		else if (lstat(argv[i], &stats) == -1)
			ft_error_2(argv[i], 0);
		else if (S_ISDIR(stats.st_mode) == 1 || S_ISLNK(stats.st_mode))
		{
			flags->s = 1;
			ft_make_all(argv[i], flags, &flags->rep, "");
		}
		else
			ft_make_all(argv[i], flags, &flags->file, "");
		i++;
	}
}

void	ft_no_path(int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "") == 0)
		{
			ft_printf("ls: fts_open: No such file or directory\n");
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}
