/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:19:51 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 20:59:54 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_grp(struct group *info_gr, t_path *file, t_flags *flags)
{
	size_t i;

	if (info_gr == NULL)
	{
		i = ft_count_cbl(file->t.st_gid, 10);
		ft_putnbr_bl(file->t.st_gid, 10);
		while (i < flags->size.gr_name)
		{
			ft_putchar(' ');
			i++;
		}
		return ;
	}
	ft_putstr(info_gr->gr_name);
	i = ft_strlen(info_gr->gr_name);
	if (S_ISLNK(file->t.st_mode))
	{
		while (i++ < flags->size.gr_name + flags->size.majeur)
			ft_putchar(' ');
		return ;
	}
	while (i++ < flags->size.gr_name)
		ft_putchar(' ');
}
