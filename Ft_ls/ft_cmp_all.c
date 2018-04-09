/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 15:36:46 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 16:08:32 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long	ft_cmp_alpha(t_path *file, t_path *link)
{
	return (ft_strcmp(file->content, link->content));
}

long	ft_cmp_reverse(t_path *file, t_path *link)
{
	return (-(ft_strcmp(file->content, link->content)));
}

long	ft_cmp_time(t_path *file, t_path *link)
{
	if ((link->t.st_mtime - file->t.st_mtime) != 0)
		return (link->t.st_mtime - file->t.st_mtime);
	else if ((link->t.st_mtimespec.tv_nsec - file->t.st_mtimespec.tv_nsec) != 0)
		return (link->t.st_mtimespec.tv_nsec - file->t.st_mtimespec.tv_nsec);
	else
		return (ft_strcmp(file->content, link->content));
}

long	ft_cmp_time_and_reverse(t_path *file, t_path *link)
{
	if ((link->t.st_mtime - file->t.st_mtime) != 0)
		return (-(link->t.st_mtime - file->t.st_mtime));
	else if ((link->t.st_mtimespec.tv_nsec - file->t.st_mtimespec.tv_nsec) != 0)
		return (-(link->t.st_mtimespec.tv_nsec - file->t.st_mtimespec.tv_nsec));
	else
		return (-(ft_strcmp(file->content, link->content)));
}

long	ft_cmp_f(t_path *file, t_path *link)
{
	if (link && file)
		return (-1);
	else
		return (-1);
}
