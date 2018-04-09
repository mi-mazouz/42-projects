/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 11:22:09 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/01 19:32:05 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	ft_jump_quote_file(char *str, char *cpy, int *i, int *j)
{
	char	c;

	c = str[*i];
	str[*i] = ' ';
	(*i)++;
	while (str[*i] != c)
	{
		cpy[*j] = str[*i];
		str[*i] = ' ';
		(*i)++;
		(*j)++;
	}
	str[*i] = ' ';
	(*i)++;
}

char		*ft_set_file(char *str, int i)
{
	char	*file;
	int		j;

	j = 0;
	if (str[i] == 0 || (str[i + 1] == 0 && str[i] == '>'))
		return (NULL);
	file = ft_strnew(ft_strlen(str));
	while (ft_isspace(str[i]) == 1)
		i++;
	while (str[i] != 0 && ft_isspace(str[i]) != 1)
	{
		if (str[i] == '>' || str[i] == '<')
			break ;
		else if (str[i] == '"' || str[i] == '\'')
		{
			ft_jump_quote_file(str, file, &i, &j);
			continue ;
		}
		file[j++] = str[i];
		str[i++] = ' ';
	}
	return (file);
}
