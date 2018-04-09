/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:45:25 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/04 09:17:10 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_make_list(t_select *sel, char **argv)
{
	int	i;

	i = 1;
	sel->file = NULL;
	sel->nb_file = 0;
	while (argv[i] != NULL)
	{
		sel->nb_file++;
		if (sel->file == NULL)
			sel->file = ft_list_add_new(ft_new_link(argv[i], i - 1));
		else
			ft_list_add_last(sel->file, ft_new_link(argv[i], i - 1));
		i++;
	}
}

t_file	*ft_new_link(char *name, size_t pos)
{
	t_file	*new;

	new = malloc(sizeof(t_file));
	new->name = ft_strdup(name);
	new->size = ft_strlen(name);
	new->pos = pos;
	new->select = 0;
	if (pos == 0)
		new->underline = 1;
	else
		new->underline = 0;
	return (new);
}

void	ft_print_list(t_list *file, t_select *sel, size_t i)
{
	t_list	*save;

	save = sel->curs;
	sel->curs = file;
	while (sel->curs != NULL)
	{
		if (++i == sel->col && sel->curs->prev != NULL)
		{
			ft_putchar_fd('\n', sel->fd);
			i = -1;
		}
		if (((t_file *)sel->curs->data)->underline == 1)
			ft_put_file(sel, 1);
		else
			ft_put_file(sel, 0);
		((t_file *)sel->curs->data)->underline = 0;
		ft_putnchar_fd(' ', (sel->max - ((t_file *)sel->curs->data)->size) + 1,
				sel->fd);
		sel->curs = sel->curs->next;
	}
	sel->curs = save;
}

size_t	ft_return_msd(t_list *list)
{
	t_list	*curs;
	size_t	i;

	curs = list->next;
	i = ((t_file *)list->data)->size;
	while (curs != NULL)
	{
		if (((t_file *)curs->data)->size > i)
			i = ((t_file *)curs->data)->size;
		curs = curs->next;
	}
	return (i);
}

void	ft_modif_pos(t_list *curs)
{
	t_list	*ptr;

	ptr = curs;
	while (ptr != NULL)
	{
		((t_file *)ptr->data)->pos--;
		ptr = ptr->next;
	}
}
