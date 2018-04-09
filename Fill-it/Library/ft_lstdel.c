/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:56:45 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/07 20:26:13 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr_1;
	t_list *ptr_2;

	ptr_1 = *alst;
	while (ptr_1->next != NULL)
	{
		ptr_2 = ptr_1->next;
		del(ptr_1->content, ptr_1->content_size);
		free(ptr_1);
		ptr_1 = ptr_2;
	}
	del(ptr_1->content, ptr_1->content_size);
	free(ptr_1);
	*alst = NULL;
}
