/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 19:15:11 by MrRobot           #+#    #+#             */
/*   Updated: 2016/02/22 17:35:53 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_recursive(char *name, t_flags *flags, t_path **list)
{
	char			*str;
	char			*tmp;
	int				i;
	int				j;

	while (*list)
	{
		i = ft_strcmp((*list)->content, ".");
		j = ft_strcmp((*list)->content, "..");
		tmp = ft_strjoin(name, "/");
		str = ft_strjoin(tmp, (*list)->content);
		free(tmp);
		if (stat(str, &(*list)->t) == -1)
			return ;
		if ((flags->a > 0 && j != 0 && i != 0 && S_ISDIR((*list)->t.st_mode)) ||
			(S_ISDIR((*list)->t.st_mode) && (*list)->content[0] != '.'))
		{
			ft_printf("\n%s:\n", str);
			ft_read_dirr(str, flags);
			free(str);
		}
		*list = (*list)->next;
	}
}
