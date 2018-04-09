/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 18:00:28 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/14 18:06:55 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tab_add_first(char **tab, char *add)
{
	char	**new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (tab == NULL)
	{
		new = ft_tabnew(1);
		new[0] = ft_strdup(add);
		return (new);
	}
	new = ft_tabnew(ft_tablen(tab) + 1);
	new[j++] = ft_strdup(add);
	while (tab[i] != NULL)
	{
		new[j] = ft_strdup(tab[i]);
		j++;
		i++;
	}
	return (new);
}

char	**ft_tab_add_last(char **tab, char *add)
{
	char	**new;
	int		i;

	i = 0;
	if (tab == NULL)
	{
		new = ft_tabnew(1);
		new[0] = ft_strdup(add);
		return (new);
	}
	new = ft_tabnew(ft_tablen(tab) + 1);
	while (tab[i] != NULL)
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = ft_strdup(add);
	return (new);
}
