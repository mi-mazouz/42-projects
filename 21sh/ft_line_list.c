/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:34:22 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/07 17:25:22 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_line_in_list(t_line *line, char c)
{
	t_list	*new;

	if (line->start == NULL)
	{
		line->start = ft_list_add_new(ft_new_link_line(c));
		line->curs = line->start;
	}
	else if (line->left == 1)
	{
		ft_list_add_first(&line->start, ft_new_link_line(c));
		line->curs = line->start;
		line->left = 0;
	}
	else if (line->curs->next == NULL)
	{
		ft_list_add_last(line->start, ft_new_link_line(c));
		ft_go_to_last(&line->curs);
	}
	else
	{
		new = ft_list_add_new(ft_new_link_line(c));
		ft_list_add_after(&line->curs, &new);
		line->curs = line->curs->next;
	}
}

char	*ft_list_in_line(t_list *start)
{
	int		i;
	char	*line;

	if (start == NULL)
		return (NULL);
	i = 0;
	line = ft_strnew(ft_list_size(start));
	while (start != NULL)
	{
		line[i] = ((t_char *)start->data)->c;
		start = start->next;
		i++;
	}
	return (line);
}

t_char	*ft_new_link_line(char c)
{
	t_char	*link;

	link = malloc(sizeof(t_char));
	link->c = c;
	link->under = 0;
	return (link);
}
