/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dirr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:57:37 by MrRobot           #+#    #+#             */
/*   Updated: 2016/02/27 05:34:03 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_read_dirr(char *name, t_flags *flags)
{
	DIR				*doss;
	struct dirent	*srt;
	t_path			*list;
	t_path			*path_l;

	flags->file = NULL;
	flags->size.nb_block = 0;
	path_l = malloc(sizeof(t_path));
	lstat(name, &path_l->t);
	if (S_ISLNK(path_l->t.st_mode) && flags->l > 0)
	{
		path_l->content = name;
		ft_print_link_2(flags, path_l, name);
		return ;
	}
	if ((doss = opendir(name)) == NULL)
		return (ft_error_2(name, 1));
	while ((srt = readdir(doss)) != NULL)
		ft_make_all(srt->d_name, flags, &flags->file, name);
	closedir(doss);
	list = flags->file;
	ft_print_file(list, flags, 1, name);
	if (flags->gr > 0)
		ft_recursive(name, flags, &list);
}
