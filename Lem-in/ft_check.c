/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:14:35 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/22 16:08:26 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_check_line(t_lemin *lemin, char *line)
{
	if (ft_strcmp("", line) == 0)
		return (0);
	else if (line[0] == 'L' && lemin->pipe.pipe == 0)
		return (0);
	else if (line[0] == '#')
	{
		if (line[1] == '#' && ft_check_cmd(&lemin->file,
					&lemin->room, line) == 0)
			return (0);
	}
	else if (lemin->ant == -1)
	{
		if (lemin->room.curs || lemin->pipe.curs ||
				(lemin->ant = ft_atoi(line)) <= 0)
			return (0);
	}
	else if (ft_set_room(&lemin->room, &lemin->pipe, line) == 0)
		return (0);
	return (1);
}

int		ft_check_cmd(t_file *file, t_room *room, char *line)
{
	char	*str;

	str = NULL;
	ft_list_add_name(&file->start, &file->curs, line);
	if (ft_strcmp("##start", line) == 0 || ft_strcmp("##end", line) == 0)
	{
		if (ft_get_next_line(0, &str) != 1)
		{
			ft_strdel(&str);
			return (0);
		}
	}
	if (ft_strcmp("##start", line) == 0)
	{
		if (ft_set_start_end(file, room, str, 0) == 0)
			return (0);
	}
	else if (ft_strcmp("##end", line) == 0)
	{
		if (ft_set_start_end(file, room, str, 1) == 0)
			return (0);
	}
	room->room = 1;
	ft_strdel(&str);
	return (1);
}

int		ft_check_dup(t_list *curs, char *chr)
{
	t_list	*ptr;

	ptr = curs;
	ft_go_to_first(&ptr);
	while (ptr != NULL)
	{
		if (ft_strcmp(((t_name *)ptr->data)->name, chr) == 0)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	ft_check_option(t_lemin *lemin, char **argv, int i)
{
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		if (argv[i][0] != '-')
			return ;
		j = 1;
		while (argv[i][j] != 0)
		{
			if (ft_isalpha(argv[i][j]) == 0)
				return ;
			if (argv[i][j] == 'p')
				lemin->p = 1;
			else if (argv[i][j] == 'c')
				lemin->c = 1;
			else if (argv[i][j] == 'n')
				lemin->n = 1;
			else if (argv[i][j] == 'h')
				lemin->h = 1;
			j++;
		}
		i++;
	}
}
