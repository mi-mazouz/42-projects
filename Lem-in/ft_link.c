/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:49:35 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/15 13:50:23 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_name	*ft_new_link_name(char *line)
{
	t_name	*new;

	new = malloc(sizeof(t_name));
	new->name = ft_strdup(line);
	return (new);
}

t_tab	*ft_new_link_tab(char **tab)
{
	t_tab	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_tab));
	new->tab = ft_tabnew(ft_tablen(tab));
	while (tab[i] != NULL)
	{
		new->tab[i] = ft_strdup(tab[i]);
		i++;
	}
	return (new);
}
