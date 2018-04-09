/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 18:40:30 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/01 19:31:41 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_strtrim_separator(char *str)
{
	char	*cmd;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i <= j && (ft_isspace(str[i]) || str[i] == ';' || str[i] == '|'))
		i++;
	while (j >= i && (ft_isspace(str[j]) || str[j] == ';' || str[j] == '|'))
		j--;
	cmd = ft_strsub(str, i, (j - i + 1));
	return (cmd);
}

int		ft_find_separator(char *cmd, char l, int test)
{
	char	c;
	int		i;

	i = ft_strlen(cmd);
	while (i >= 0)
	{
		if (cmd[i] == '"' || cmd[i] == '\'')
		{
			c = cmd[i--];
			while (cmd[i] != c)
				i--;
		}
		else if (cmd[i] == l)
			return (i);
		i--;
	}
	if (test == 0)
		return (ft_find_separator(cmd, '|', 1));
	return (-1);
}
