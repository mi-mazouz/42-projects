/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:02:55 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/04 22:58:47 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_list(t_stack **all, char *str)
{
	t_stack		*ptr;
	t_stack		*curs;

	ptr = malloc(sizeof(t_stack));
	ptr->number = ft_atoi_l(str);
	ptr->next = NULL;
	ptr->prev = NULL;
	if ((*all) == NULL)
	{
		(*all) = ptr;
		return ;
	}
	curs = (*all);
	while (curs->next != NULL)
		curs = curs->next;
	ptr->prev = curs;
	curs->next = ptr;
}
