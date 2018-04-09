/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:19:56 by MrRobot           #+#    #+#             */
/*   Updated: 2016/06/16 23:08:05 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_add_first(t_list **list, void *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->prev = NULL;
	new->next = *list;
	(*list)->prev = new;
	new->data = data;
	*list = new;
}

void	ft_list_add_last(t_list *list, void *data)
{
	t_list	*new;
	t_list	*curs;

	curs = list;
	while (curs->next != NULL)
		curs = curs->next;
	new = malloc(sizeof(t_list));
	new->prev = curs;
	curs->next = new;
	new->data = data;
	new->next = NULL;
}

void	ft_list_add_after(t_list **curs, t_list **new)
{
	(*new)->next = (*curs)->next;
	(*new)->prev = *curs;
	(*curs)->next->prev = *new;
	(*curs)->next = *new;
}

void	ft_list_add_before(t_list **curs, t_list **new)
{
	(*new)->next = *curs;
	(*new)->prev = (*curs)->prev;
	(*curs)->prev->next = *new;
	(*curs)->prev = *new;
}

t_list	*ft_list_add_new(void *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
