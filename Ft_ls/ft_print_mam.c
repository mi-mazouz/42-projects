/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:25:57 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 16:37:10 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	ft_init_count(t_path *file, int k)
{
	if (k == 0)
		return (ft_count_cbl(major(file->t.st_rdev), 10));
	else
		return (ft_count_cbl(minor(file->t.st_rdev), 10));
}

void	ft_print_mam(t_path *file, t_flags *flags)
{
	size_t i;
	size_t j;

	if ((S_IFCHR & file->t.st_mode || S_IFBLK & file->t.st_mode) &&
		(!S_ISDIR(file->t.st_mode)) && (!S_ISLNK(file->t.st_mode)))
	{
		flags->size.p = 1;
		ft_putchar(' ');
		i = major(file->t.st_rdev) == 0 ? 1 : ft_init_count(file, 0);
		j = minor(file->t.st_rdev) == 0 ? 1 : ft_init_count(file, 1);
		while (i < flags->size.majeur)
		{
			ft_putchar(' ');
			i++;
		}
		ft_printf("%d, ", major(file->t.st_rdev));
		while (j < flags->size.mineur)
		{
			ft_putchar(' ');
			j++;
		}
		ft_printf("%d ", minor(file->t.st_rdev));
	}
	else
		ft_print_mam_2(file, flags);
}

void	ft_print_mam_2(t_path *file, t_flags *flags)
{
	size_t i;

	if (flags->size.p == 1)
	{
		i = ft_count_cbl(minor(file->t.st_rdev), 10) +
			ft_count_cbl(minor(file->t.st_rdev), 10) + 2;
		while (i < flags->size.mineur + flags->size.majeur + 4)
		{
			ft_putchar(' ');
			i++;
		}
		ft_printf("%lu ", file->t.st_size);
	}
	else
		ft_print_mam_3(file, flags);
}

void	ft_print_mam_3(t_path *file, t_flags *flags)
{
	size_t i;

	i = ft_count_cbl(file->t.st_size, 10);
	if (flags->size.mineur > 0 && flags->size.majeur > 0)
	{
		while (i < flags->size.mineur + flags->size.majeur + 3)
		{
			ft_putchar(' ');
			i++;
		}
	}
	else
	{
		while (i < flags->size.nb_octet)
		{
			ft_putchar(' ');
			i++;
		}
	}
	ft_printf("%lu ", file->t.st_size);
}
