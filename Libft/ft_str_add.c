/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 19:00:01 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/23 15:45:43 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_add_str_index(char *str, char *insert, int i)
{
	char	*new;
	char	*tmp;
	char	*tmp_2;
	char	*tmp_3;

	tmp = ft_strsub(str, 0, i);
	tmp_2 = ft_strsub(str, i, ft_strlen(str) - i);
	tmp_3 = ft_strjoin(insert, tmp_2);
	free(tmp_2);
	new = ft_strjoin(tmp, tmp_3);
	free(tmp);
	free(tmp_3);
	return (new);
}

char	*ft_str_add_index(char *str, char c, int i)
{
	char	*new;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (str == NULL)
		return (ft_strdup(&c));
	new = ft_strnew(ft_strlen(str) + 1);
	while (str[k] != 0)
	{
		if (j == i)
		{
			new[j++] = c;
			continue ;
		}
		new[j++] = str[k++];
	}
	return (new);
}

char	*ft_str_add_last(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (str == NULL)
		return (ft_strdup(&c));
	new = ft_strnew(ft_strlen(str) + 1);
	while (str[i] != 0)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	return (new);
}

char	*ft_str_add_first(char *str, char c)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (ft_strdup(&c));
	new = ft_strnew(ft_strlen(str) + 1);
	new[j++] = c;
	while (str[i] != 0)
	{
		new[j] = str[i];
		i++;
		j++;
	}
	return (new);
}
