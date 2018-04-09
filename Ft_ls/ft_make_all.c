/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:54:45 by MrRobot           #+#    #+#             */
/*   Updated: 2016/02/24 14:14:33 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_make_all(char *file, t_flags *flags, t_path **all, char *name)
{
	t_path *curs;
	t_path *ptr;

	if ((ptr = ft_creat_elem(file, flags, all, name)) == NULL)
		return ;
	curs = *all;
	if (flags->l > 0 && (flags->a > 0 || ptr->content[0] != '.'))
		ft_init_size(flags, ptr);
	if (flags->cmp(curs, ptr) >= 0)
	{
		ptr->next = curs;
		*all = ptr;
		return ;
	}
	while (curs->next != NULL)
	{
		if (flags->cmp(curs->next, ptr) >= 0)
		{
			ptr->next = curs->next;
			curs->next = ptr;
			return ;
		}
		curs = curs->next;
	}
	curs->next = ptr;
}
