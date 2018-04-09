/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_go_to.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 20:55:07 by MrRobot           #+#    #+#             */
/*   Updated: 2016/06/01 15:53:05 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_go_to_first(t_list **list)
{
	if (*list == NULL)
		return ;
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
}

void	ft_go_to_last(t_list **list)
{
	if (*list == NULL)
		return ;
	while ((*list)->next != NULL)
		*list = (*list)->next;
}
