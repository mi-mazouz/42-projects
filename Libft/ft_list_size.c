/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 16:10:39 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:12:25 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_list_size(t_list *list)
{
	size_t	i;
	t_list	*curs;

	i = 0;
	curs = list;
	while (curs != NULL)
	{
		curs = curs->next;
		i++;
	}
	return (i);
}
