/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_law_grp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:47:51 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 20:57:55 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_law_usr(t_flags *flags, t_path *file)
{
	if (S_ISDIR(file->t.st_mode))
		ft_putchar('d');
	else if (S_ISLNK(file->t.st_mode))
		ft_putchar('l');
	else if (S_ISCHR(file->t.st_mode))
		ft_putchar('c');
	else if (S_ISBLK(file->t.st_mode))
		ft_putchar('b');
	else if (S_ISSOCK(file->t.st_mode))
		ft_putchar('s');
	else
		ft_putchar('-');
	file->t.st_mode & S_IRUSR ? ft_putchar('r') : ft_putchar('-');
	file->t.st_mode & S_IWUSR ? ft_putchar('w') : ft_putchar('-');
	if ((file->t.st_mode & S_IXUSR) && (file->t.st_mode & S_ISVTX))
		ft_putchar('s');
	else if (file->t.st_mode & S_ISVTX)
		ft_putchar('S');
	else if (file->t.st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
	ft_print_law_grp(flags, file);
}

void	ft_print_law_grp(t_flags *flags, t_path *file)
{
	file->t.st_mode & S_IRGRP ? ft_putchar('r') : ft_putchar('-');
	file->t.st_mode & S_IWGRP ? ft_putchar('w') : ft_putchar('-');
	if ((file->t.st_mode & S_IXGRP) && (file->t.st_mode & S_ISVTX))
		ft_putchar('s');
	else if (file->t.st_mode & S_ISVTX)
		ft_putchar('S');
	else if (file->t.st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
	ft_print_law_oth(flags, file);
}

void	ft_print_law_oth(t_flags *flags, t_path *file)
{
	file->t.st_mode & S_IROTH ? ft_putchar('r') : ft_putchar('-');
	file->t.st_mode & S_IWOTH ? ft_putchar('w') : ft_putchar('-');
	if ((file->t.st_mode & S_IXOTH) && (file->t.st_mode & S_ISVTX))
		ft_putchar('t');
	else if (file->t.st_mode & S_ISVTX)
		ft_putchar('T');
	else if (file->t.st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
	ft_putstr("  ");
	ft_print_nb_link(flags, file);
}
