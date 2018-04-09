/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:43:31 by MrRobot           #+#    #+#             */
/*   Updated: 2016/02/25 13:49:52 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free_lst(t_path **file)
{
	t_path *curs;
	t_path *ptr;

	ptr = *file;
	while (ptr != NULL)
	{
		curs = ptr->next;
		free(ptr);
		ptr = curs;
	}
}
