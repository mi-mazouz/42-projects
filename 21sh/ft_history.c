/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 13:00:25 by MrRobot           #+#    #+#             */
/*   Updated: 2016/06/14 20:41:32 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_history_bottom(t_his *his, t_line *line)
{
	if (his->start == NULL || his->go == 0)
		return ;
	if (his->curs->next != NULL)
		his->curs = his->curs->next;
	ft_home(line);
	line->left = 0;
	if (line->start != NULL)
	{
		ft_list_del_all(&line->start, ft_free);
		line->curs = NULL;
	}
	tputs(tgetstr("cd", NULL), 0, ft_put);
	if (his->left == 0 && his->go == 1)
	{
		ft_put_line(his->curs->data);
		line->start = ft_copy_line(his->curs->data);
		line->curs = line->start;
		ft_go_to_last(&line->curs);
		if (his->curs->next == NULL)
			his->left = 1;
		return ;
	}
	his->go = 0;
}

void	ft_history_top(t_his *his, t_line *line)
{
	if (his->start == NULL || (his->go == 1 && his->curs->prev == NULL))
		return ;
	if (his->curs->prev != NULL && his->go == 1)
		his->curs = his->curs->prev;
	ft_home(line);
	line->left = 0;
	if (line->start != NULL)
	{
		ft_list_del_all(&line->start, ft_free);
		line->curs = NULL;
	}
	tputs(tgetstr("cd", NULL), 0, ft_put);
	ft_put_line(his->curs->data);
	line->start = ft_copy_line(his->curs->data);
	line->curs = line->start;
	ft_go_to_last(&line->curs);
	his->left = 0;
	if (his->curs->next == NULL)
		his->left = 1;
	his->go = 1;
}
