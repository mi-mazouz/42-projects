/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 17:35:38 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/20 17:36:40 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print_file(t_list *start)
{
	t_list *ptr;

	ptr = start;
	while (ptr != NULL)
	{
		ft_putendl(((t_name *)ptr->data)->name);
		ptr = ptr->next;
	}
}

void	ft_print_ant_course(char **path, t_lemin *lemin)
{
	int		nbc;

	nbc = 0;
	if (lemin->p == 1)
	{
		ft_putstr("\nPath: ");
		ft_puttab(path, '-');
		ft_putchar('\n');
	}
	ft_putchar('\n');
	ft_first_print(path, lemin, &nbc);
	ft_last_print(path, lemin, &nbc);
	if (lemin->n == 1)
		ft_printf("\nNombre de coups: %d", nbc);
}

void	ft_put_colors(int c, int ant, char *room)
{
	if (c == 1)
		ft_printf("L%s%d%s-%s%s%s ", RED, ant, STOP, BLUE, room, STOP);
	else
		ft_printf("L%d-%s ", ant, room);
}

void	ft_first_print(char **path, t_lemin *lemin, int *nbc)
{
	int	i;
	int	k;
	int s;

	i = 1;
	while (path[i] != NULL)
	{
		k = 1;
		s = i;
		while (k < i && k < lemin->ant)
		{
			ft_put_colors(lemin->c, k, path[s]);
			s--;
			k++;
		}
		ft_put_colors(lemin->c, k, path[s]);
		ft_putchar('\n');
		(*nbc)++;
		i++;
	}
}

void	ft_last_print(char **path, t_lemin *lemin, int *nbc)
{
	int	k;
	int	p;
	int	s;
	int	j;
	int	l;

	k = 2;
	p = (lemin->ant - 1);
	while (k <= lemin->ant)
	{
		l = k;
		j = 1;
		s = ft_tablen(path) - 1;
		while (j <= (p - 1) && s > 1)
		{
			ft_put_colors(lemin->c, l, path[s--]);
			l++;
			j++;
		}
		ft_put_colors(lemin->c, l, path[s]);
		ft_putchar('\n');
		(*nbc)++;
		p--;
		k++;
	}
}
