/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 15:54:18 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 19:49:37 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_one_path(t_flags *flags)
{
	if (flags->road < 2)
	{
		flags->rep = malloc(sizeof(t_path));
		flags->rep->content = ft_strdup(".");
		flags->rep->next = NULL;
	}
	flags->p = 1;
	ft_initialise_cmp(flags);
	ft_read_dirr(flags->rep->content, flags);
	ft_free_lst(&flags->rep);
}
