/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 18:45:33 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/24 15:28:29 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*ft_remove_quote_str(char *str)
{
	char	*result;
	char	*cmd;
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cmd = ft_treat_special_char(str);
	result = ft_strnew((ft_strlen(cmd)));
	while (cmd[i] != 0)
	{
		if (cmd[i] == '"' || cmd[i] == '\'' || cmd[i] == '`')
		{
			c = cmd[i++];
			while (cmd[i] != c)
				result[j++] = cmd[i++];
			i++;
		}
		else
			result[j++] = cmd[i++];
	}
	free(cmd);
	return (result);
}

char		**ft_remove_quote_tab(char **tab)
{
	char	**cmd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cmd = ft_tabnew(ft_tablen(tab));
	while (tab[i] != NULL)
	{
		cmd[j] = ft_remove_quote_str(tab[i]);
		i++;
		j++;
	}
	return (cmd);
}

int			ft_isquote(char c)
{
	if (c == '\'' || c == '"' || c == '`')
		return (1);
	return (0);
}

void		ft_jump_quote(char *str, int *i)
{
	char	c;

	c = str[*i];
	(*i)++;
	while (str[*i] != c)
		(*i)++;
}
