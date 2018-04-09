/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:59:39 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/08 12:15:27 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *ptr_1;
	t_list *ptr_2;

	ptr_1 = lst;
	while (ptr_1->next != NULL)
	{
		ptr_2 = ptr_1->next;
		f(ptr_1);
		ptr_1 = ptr_2;
	}
	f(ptr_1);
}
