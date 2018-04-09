/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:15:14 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/29 13:24:19 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_colors(t_flags *flags, t_path *file, char *name, char *str)
{
	if ((flags->a > 0 || flags->f > 0) ||
			(file->content[0] != '.' || flags->p == 0))
	{
		if (flags->l > 0)
			ft_print_link(flags, file, name);
		else if (S_ISDIR(file->t.st_mode))
			ft_printf("%s""%s\n""%s", BLUE, file->content, STOP);
		else if (S_ISLNK(file->t.st_mode))
			ft_printf("%s""%s\n""%s", YELLOW, file->content, STOP);
		else if (access(str, X_OK) == 0)
			ft_printf("%s""%s\n""%s", RED, file->content, STOP);
		else
			ft_printf("%s\n", file->content);
	}
}
