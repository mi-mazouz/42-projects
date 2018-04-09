/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 19:39:09 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/29 13:23:56 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_link(t_flags *flags, t_path *file, char *name)
{
	size_t	len;
	char	*path;
	char	*buff;
	char	*tmp;

	len = 4096;
	buff = (char *)malloc(sizeof(char) * len);
	tmp = ft_strjoin(name, "/");
	path = ft_strjoin(tmp, file->content);
	ft_strclr(buff, len);
	readlink(path, buff, len);
	if (flags->l > 0)
		ft_print_law_usr(flags, file);
	if (S_ISLNK(file->t.st_mode))
		ft_printf("%s%s%s -> %s\n", YELLOW, file->content, STOP, buff);
	else if (S_ISDIR(file->t.st_mode))
		ft_printf("%s%s%s\n", BLUE, file->content, STOP);
	else if (access(path, X_OK) == 0)
		ft_printf("%s%s%s\n", RED, file->content, STOP);
	else
		ft_printf("%s\n", file->content);
	free(tmp);
	free(path);
}

void	ft_print_link_2(t_flags *flags, t_path *link, char *name)
{
	size_t	len;
	char	*buff;

	ft_print_law_usr(flags, link);
	len = 4096;
	buff = (char *)malloc(sizeof(char) * len);
	ft_strclr(buff, len);
	readlink(name, buff, len);
	ft_printf("%s%s%s -> %s\n", YELLOW, name, STOP, buff);
}
