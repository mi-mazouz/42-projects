/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_and_paste.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 17:34:06 by MrRobot           #+#    #+#             */
/*   Updated: 2016/07/14 14:10:44 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_select_in_line(t_line *line)
{
	t_list	*ptr;
	int		col;
	int		row;
	int		i;

	if (line->start == NULL || (line->curs->next == NULL && line->left == 0))
		return ;
	ptr = line->curs;
	col = ft_curs_pos_col(g_shell.fd.fd);
	row = ft_curs_pos_row(g_shell.fd.fd);
	tputs(tgetstr("cd", NULL), 0, ft_put);
	if (line->curs->prev != NULL || line->left != 1)
	{
		ptr = line->curs->next;
		line->curs = line->curs->next;
	}
	if (((t_char *)ptr->data)->under == 1)
		((t_char *)ptr->data)->under = 0;
	else
		((t_char *)ptr->data)->under = 1;
	i = ft_put_line(ptr);
	tputs(tgoto(tgetstr("cm", NULL), col, row - i), 0, ft_put);
	line->left = 0;
	if (col == line->win.ws_col)
		tputs(tgetstr("do", NULL), 0, ft_put);
}

void	ft_cut_select(t_line *line)
{
	t_list	*ptr;

	if (line->start == NULL || (ft_check_cut(line->start) == 0))
		return ;
	ptr = line->start;
	ft_copy_select(line);
	ft_home(line);
	tputs(tgetstr("cd", NULL), 0, ft_put);
	while (ptr != NULL)
	{
		if (((t_char *)ptr->data)->under == 1)
			ft_free_cut(line, &ptr);
		else
			ptr = ptr->next;
	}
	ft_put_line(line->start);
	line->curs = line->start;
	ft_go_to_last(&line->curs);
	line->left = 0;
}

void	ft_paste_copy(t_line *line)
{
	t_list	*ptr;
	t_list	*save_curs;
	int		left;

	if (line->start == NULL || line->copy.start == NULL)
		return ;
	ptr = line->copy.start;
	save_curs = line->curs;
	left = line->left;
	tputs(tgetstr("cd", NULL), 0, ft_put);
	while (ptr != NULL)
	{
		ft_line_in_list(line, ((t_char *)ptr->data)->c);
		if (line->curs->prev == NULL)
			save_curs = line->curs;
		ptr = ptr->next;
	}
	line->curs = save_curs;
	if (line->curs->prev == NULL && left == 1)
		ft_put_line(line->curs);
	else
		ft_put_line(line->curs->next);
	ft_go_to_last(&line->curs);
}

int		ft_check_cut(t_list *start)
{
	t_list *ptr;

	ptr = start;
	while (ptr != NULL)
	{
		if (((t_char *)ptr->data)->under == 1)
			return (1);
		else
			ptr = ptr->next;
	}
	return (0);
}
