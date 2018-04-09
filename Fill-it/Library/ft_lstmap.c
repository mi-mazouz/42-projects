/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:00:35 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/08 15:30:57 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ptr_1;
	t_list *ptr_2;
	t_list *new;

	if (!f || !lst)
		return (NULL);
	ptr_1 = lst->next;
	new = (*f)(lst);
	ptr_2 = new;
	while (ptr_1 != NULL)
	{
		ptr_2->next = (*f)(ptr_1);
		ptr_1 = ptr_1->next;
		ptr_2 = ptr_2->next;
	}
	ptr_2->next = NULL;
	return (new);
}
