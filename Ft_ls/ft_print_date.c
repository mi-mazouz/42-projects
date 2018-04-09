/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_date.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 19:40:05 by MrRobot           #+#    #+#             */
/*   Updated: 2016/02/24 13:31:50 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_date(t_path *file)
{
	char			*tmp;
	char			*tmp_2;
	char			*time_all;
	time_t			t;

	t = time(NULL);
	if (((t - file->t.st_mtime) > 15768000) || ((t - file->t.st_mtime) < 0))
	{
		time_all = ctime(&file->t.st_mtime);
		tmp = ft_strsub(time_all, 4, 7);
		ft_printf("%s ", tmp);
		tmp_2 = ft_strsub(time_all, 20, 4);
		ft_printf("%s ", tmp_2);
		free(tmp);
		free(tmp_2);
	}
	else
		ft_printf("%s ", (ft_strsub(ctime(&file->t.st_mtime), 4, 12)));
}
