/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:28:38 by MrRobot           #+#    #+#             */
/*   Updated: 2016/07/10 15:47:42 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_del_last_one(t_list **list, void (*f)(void *data))
{
	(*f)((*list)->data);
	free(*list);
	*list = NULL;
}

void	ft_list_del_last(t_list **list, void (*f)(void *data))
{
	t_list	*ptr;

	ptr = *list;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->prev->next = NULL;
	(*f)(ptr->data);
	free(ptr);
}

void	ft_list_del_first(t_list **list, void (*f)(void *data))
{
	t_list	*ptr;

	ptr = *list;
	*list = (*list)->next;
	(*list)->prev = NULL;
	(*f)(ptr->data);
	free(ptr);
}

void	ft_list_del(t_list *del, void (*f)(void *data))
{
	del->prev->next = del->next;
	del->next->prev = del->prev;
	(*f)(del->data);
	free(del);
}

void	ft_list_del_all(t_list **list, void (*f)(void *data))
{
	t_list	*ptr;

	while (*list != NULL)
	{
		ptr = *list;
		*list = (*list)->next;
		(*f)(ptr->data);
		free(ptr);
	}
	*list = NULL;
}
