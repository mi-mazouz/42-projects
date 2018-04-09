/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 19:45:05 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 16:54:46 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_path	*ft_creat_elem(char *file, t_flags *flags, t_path **all, char *name)
{
	char	*tmp;
	char	*tmp_2;
	t_path	*ptr;

	if ((flags->a > 0 || flags->f > 0) || (file[0] != '.' || flags->p == 0))
	{
		if ((ft_strcmp(name, "") != 0))
			tmp = ft_strjoin(name, "/");
		ft_norminette(&tmp, &tmp_2, &ptr, file);
		if (flags->a > 0 || flags->f > 0)
			flags->size.nb_block = flags->size.nb_block + ptr->t.st_blocks;
		else if (ptr->content[0] != '.')
			flags->size.nb_block = flags->size.nb_block + ptr->t.st_blocks;
	}
	else
		return (NULL);
	if (*all == NULL)
	{
		*all = ptr;
		if (flags->l > 0)
			ft_initialise_first_all(flags, all);
		return (NULL);
	}
	return (ptr);
}

void	ft_initialise_first_all(t_flags *flags, t_path **all)
{
	if (flags->a > 0 || flags->f > 0 || (*all)->content[0] != '.')
	{
		ft_norminette_2(flags, all);
		return ;
	}
}

void	ft_init_size(t_flags *flags, t_path *ptr)
{
	struct passwd	*info;
	struct group	*info_gr;

	info = getpwuid(ptr->t.st_uid);
	info_gr = getgrgid(ptr->t.st_gid);
	if (flags->size.nb_link < ft_count_cbul(ptr->t.st_nlink, 10))
		flags->size.nb_link = ft_count_cbul(ptr->t.st_nlink, 10);
	if (info == NULL)
	{
		if (flags->size.pw_name < ft_count_cbul(ptr->t.st_uid, 10))
			flags->size.pw_name = ft_count_cbul(ptr->t.st_uid, 10);
	}
	else if (flags->size.pw_name < ft_strlen(info->pw_name))
		flags->size.pw_name = ft_strlen(info->pw_name);
	if (info_gr == NULL)
	{
		if (flags->size.gr_name < ft_count_cbul(ptr->t.st_gid, 10))
			flags->size.gr_name = ft_count_cbul(ptr->t.st_gid, 10);
	}
	else if (flags->size.gr_name < ft_strlen(info_gr->gr_name))
		flags->size.gr_name = ft_strlen(info_gr->gr_name);
	ft_norminette_3(flags, ptr);
}
