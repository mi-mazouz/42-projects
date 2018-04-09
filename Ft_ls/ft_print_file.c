/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:41:25 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 20:49:07 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_file(t_path *file, t_flags *flags, int i, char *name)
{
	char *tmp;
	char *str;

	tmp = ft_strjoin(name, "/");
	if (flags->l > 0 && i == 1 && file != NULL)
		ft_printf("total %ld\n", flags->size.nb_block);
	while (file != NULL)
	{
		str = ft_strjoin(tmp, file->content);
		ft_print_colors(flags, file, name, str);
		if (flags->rep)
		{
			if (file->next == NULL && flags->rep->next != NULL)
				ft_putchar('\n');
		}
		file = file->next;
		free(str);
	}
	free(tmp);
}

void	ft_print_nb_link(t_flags *flags, t_path *file)
{
	size_t			i;
	struct passwd	*info;
	struct group	*info_gr;

	info = getpwuid(file->t.st_uid);
	info_gr = getgrgid(file->t.st_gid);
	i = ft_count_cbl(file->t.st_nlink, 10);
	while (i < flags->size.nb_link)
	{
		ft_putchar(' ');
		i++;
	}
	ft_printf("%ld ", file->t.st_nlink);
	ft_print_usr(info, file, flags);
	ft_print_grp(info_gr, file, flags);
	ft_putstr("  ");
	ft_print_mam(file, flags);
	ft_print_octet(flags, file);
	ft_print_date(file);
}

void	ft_print_octet(t_flags *flags, t_path *file)
{
	size_t i;

	i = ft_strlen(ctime(&file->t.st_mtime));
	while (i < flags->size.size_h)
	{
		ft_putchar(' ');
		i++;
	}
}
