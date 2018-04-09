/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:09:44 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/22 16:10:05 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	**ft_remove_tab(char **neigh, char **tmp, char *str)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	while (tmp[i] != NULL)
	{
		j = 0;
		while (neigh[j] != NULL)
		{
			if (ft_strcmp(tmp[i], neigh[j]) == 0 || ft_strcmp(tmp[i], str) == 0)
			{
				free(tmp[i]);
				tmp[i] = ft_strdup("");
				break ;
			}
			j++;
		}
		i++;
	}
	new = ft_new_tab(tmp);
	ft_free_tab(neigh);
	ft_free_tab(tmp);
	return (new);
}

char	**ft_new_tab(char **tmp)
{
	int		i;
	int		j;
	char	**new;
	char	**tmp2;

	i = 0;
	j = 0;
	new = NULL;
	while (tmp[i] != NULL)
	{
		if (ft_strcmp(tmp[i], "") != 0)
		{
			if (new == NULL)
				new = ft_tab_add_last(new, tmp[i]);
			else
			{
				tmp2 = ft_tab_add_last(new, tmp[i]);
				ft_free_tab(new);
				new = tmp2;
			}
		}
		i++;
	}
	return (new);
}
