/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 13:35:10 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/29 13:22:26 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_error(char c)
{
	ft_printf("ls: illegal option -- %c\nusage: ls [-Raflrt] [file ...]\n", c);
	return (1);
}

void	ft_error_2(char *name, int k)
{
	struct stat	info;
	int			i;

	i = lstat(name, &info);
	if (i == -1 && k == 0)
		ft_printf("ls: %s: No such file or directory\n", name);
	else if (i != -1 && k == 1 && (!S_ISLNK(info.st_mode)) &&
			(!S_ISREG(info.st_mode)))
		ft_printf("ls: %s: Permission denied\n", name);
	else if (S_ISLNK(info.st_mode))
		ft_printf("%s%s%s\n", YELLOW, name, STOP);
}
