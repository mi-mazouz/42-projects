/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:16:29 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/20 12:16:30 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabjoin(char **tab1, char **tab2)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_tabnew(ft_tablen(tab1) + ft_tablen(tab2));
	while (tab1[i] != NULL)
	{
		new[i] = ft_strdup(tab1[i]);
		i++;
	}
	while (tab2[j] != NULL)
	{
		new[i] = ft_strdup(tab2[j]);
		i++;
		j++;
	}
	return (new);
}
