/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norminette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:41:15 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 17:05:32 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_norminette(char **tmp, char **tmp_2, t_path **ptr, char *file)
{
	if ((ft_strcmp(file, "") != 0))
		*tmp_2 = ft_strjoin(*tmp, file);
	*ptr = malloc(sizeof(t_path));
	(*ptr)->content = ft_strdup(file);
	if ((ft_strcmp(file, "") != 0))
		lstat(*tmp_2, &(*ptr)->t);
	(*ptr)->next = NULL;
}

void	ft_norminette_2(t_flags *flags, t_path **all)
{
	struct passwd	*info;
	struct group	*info_gr;

	info = getpwuid((*all)->t.st_uid);
	info_gr = getgrgid((*all)->t.st_gid);
	flags->size.nb_link = ft_count_cbl((*all)->t.st_nlink, 10);
	if (info == NULL)
		flags->size.pw_name = ft_count_cbl((*all)->t.st_uid, 10);
	else
		flags->size.pw_name = ft_strlen(info->pw_name);
	if (info_gr == NULL)
		flags->size.gr_name = ft_count_cbl((*all)->t.st_gid, 10);
	else
		flags->size.gr_name = ft_strlen(info_gr->gr_name);
	if ((S_IFCHR & (*all)->t.st_mode || S_IFBLK & (*all)->t.st_mode) &&
			(!S_ISDIR((*all)->t.st_mode)) && (!S_ISLNK((*all)->t.st_mode)))
	{
		flags->size.majeur =
		ft_count_cbl(major((*all)->t.st_rdev), 10);
		flags->size.mineur =
		ft_count_cbl(minor((*all)->t.st_rdev), 10);
	}
	else
		flags->size.nb_octet = ft_count_cbl((*all)->t.st_size, 10);
	flags->size.size_h = ft_strlen(ctime(&(*all)->t.st_mtime));
}

void	ft_norminette_3(t_flags *flags, t_path *ptr)
{
	if ((S_IFCHR & ptr->t.st_mode || S_IFBLK & ptr->t.st_mode) &&
		(!S_ISDIR(ptr->t.st_mode)) && (!S_ISLNK(ptr->t.st_mode)))
	{
		if (flags->size.majeur < ft_count_cbul(major(ptr->t.st_rdev), 10))
			flags->size.majeur = ft_count_cbul(major(ptr->t.st_rdev), 10);
		if (flags->size.mineur < ft_count_cbul(minor(ptr->t.st_rdev), 10))
			flags->size.mineur = ft_count_cbul(minor(ptr->t.st_rdev), 10);
	}
	else
	{
		if (flags->size.nb_octet < ft_count_cbul(ptr->t.st_size, 10))
			flags->size.nb_octet = ft_count_cbul(ptr->t.st_size, 10);
	}
	if (flags->size.size_h < ft_strlen(ctime(&ptr->t.st_mtime)))
		flags->size.size_h = ft_strlen(ctime(&ptr->t.st_mtime));
}
