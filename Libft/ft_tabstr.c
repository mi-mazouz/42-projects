/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_in_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 13:44:51 by MrRobot           #+#    #+#             */
/*   Updated: 2016/06/23 13:50:16 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tabstr(char **tab)
{
	int		i;
	char	*tmp;
	char	*str;

	i = 0;
	while (tab[i] != NULL)
	{
		if (i == 0)
			str = ft_strdup(tab[i]);
		else
		{
			tmp = ft_strjoin(str, tab[i]);
			free(str);
			str = ft_strdup(tmp);
			free(tmp);
		}
		i++;
	}
	return (str);
}
