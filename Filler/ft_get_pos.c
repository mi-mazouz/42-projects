/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:40:46 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/26 17:16:12 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_list	*ft_get_pos_dif(char **tab, char **dif, char letter)
{
	int		i;
	int		j;
	t_list	*pos;

	i = 0;
	pos = NULL;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != 0)
		{
			if (tab[i][j] == letter && dif[i][j] == '.')
			{
				if (pos == NULL)
					pos = ft_list_add_new(ft_new_link(i, j));
				else
					ft_list_add_last(pos, ft_new_link(i, j));
			}
			j++;
		}
		i++;
	}
	return (pos);
}

t_list	*ft_get_all_pos(char **tab, char letter)
{
	int		i;
	int		j;
	t_list	*pos;

	i = 0;
	pos = NULL;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != 0)
		{
			if (tab[i][j] == letter)
			{
				if (pos == NULL)
					pos = ft_list_add_new(ft_new_link(i, j));
				else
					ft_list_add_last(pos, ft_new_link(i, j));
			}
			j++;
		}
		i++;
	}
	return (pos);
}

int		*ft_get_close_pos(t_list **pos_me, t_list *pos_enemy)
{
	t_list	*ptr;
	int		*pos;
	int		dif;

	ptr = pos_enemy;
	while (ptr != NULL)
	{
		if (((t_pos *)(*pos_me)->data)->dif == -1)
		{
			ft_calculate_dif(pos_me, ((t_pos *)ptr->data)->pos);
			dif = ((t_pos *)(*pos_me)->data)->dif;
			pos = ((t_pos *)ptr->data)->pos;
		}
		else
		{
			ft_calculate_dif(pos_me, ((t_pos *)ptr->data)->pos);
			if (dif > ((t_pos *)(*pos_me)->data)->dif)
			{
				dif = ((t_pos *)(*pos_me)->data)->dif;
				pos = ((t_pos *)ptr->data)->pos;
			}
		}
		ptr = ptr->next;
	}
	return (pos);
}

int	*ft_get_rush_pos(char **tab, char letter)
{
	int	i;
	int	j;
	int	*pos;

	i = 0;
	j = 0;
	pos = (int *)malloc(sizeof(int) * 2);
	while (tab[i] != NULL && (j = ft_strchri(tab[i], letter)) == -1)
		i++;
	pos[0] = i;
	pos[1] = j;
	return (pos);
}
