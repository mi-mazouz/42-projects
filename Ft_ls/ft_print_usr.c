/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:17:39 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 16:37:35 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_usr(struct passwd *info, t_path *file, t_flags *flags)
{
	size_t i;

	if (info == NULL)
	{
		i = ft_count_cbl(file->t.st_uid, 10);
		ft_putnbr_bl(file->t.st_uid, 10);
		while (i < flags->size.pw_name)
		{
			ft_putchar(' ');
			i++;
		}
	}
	else
	{
		i = ft_strlen(info->pw_name);
		ft_putstr(info->pw_name);
		while (i < flags->size.pw_name)
		{
			ft_putchar(' ');
			i++;
		}
	}
	ft_putstr("  ");
}
