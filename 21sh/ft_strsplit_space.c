/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 16:10:26 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/30 10:06:54 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		ft_count_w(char *str)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (str[i] != 0)
	{
		while (str[i] != 0 && ft_isspace(str[i]) == 1)
			i++;
		if (str[i] == 0)
			break ;
		while (str[i] != 0 && ft_isspace(str[i]) != 1)
		{
			if (str[i] == '"' || str[i] == '\'')
				ft_jump_quote(str, &i);
			i++;
		}
		words++;
	}
	return (words);
}

static void		ft_jump_quote_split(char *str, int st, int *len)
{
	char	c;

	c = str[st + *len];
	(*len)++;
	while (str[st + *len] != c)
		(*len)++;
}

char			**ft_strsplit_space(char *str)
{
	int		i;
	int		st;
	int		len;
	char	**tab;

	st = 0;
	i = 0;
	tab = ft_tabnew(ft_count_w(str));
	while (i < ft_count_w(str))
	{
		while (str[st] != 0 && ft_isspace(str[st]) == 1)
			st++;
		len = 0;
		while (str[st + len] != 0 && ft_isspace(str[st + len]) != 1)
		{
			if (str[st + len] == '"' || str[st + len] == '\'')
				ft_jump_quote_split(str, st, &len);
			len++;
		}
		tab[i] = ft_strsub(str, st, len);
		st = st + len;
		i++;
	}
	return (tab);
}
