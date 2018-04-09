/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_special_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:18:42 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/24 15:28:25 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	*ft_treat_special_char_in_quote(char *str, int *i)
{
	char	c;

	c = str[*i];
	(*i)++;
	while (str[*i] != c)
	{
		if (str[*i] == '$' && c == '"')
			str = ft_treat_dollars(str, i);
		(*i)++;
	}
	return (str);
}

char		*ft_treat_special_char(char *str)
{
	int		i;
	char	*cmd;

	i = 0;
	cmd = ft_strdup(str);
	while (cmd[i] != 0)
	{
		if (cmd[i] == '"' || cmd[i] == '\'')
			cmd = ft_treat_special_char_in_quote(cmd, &i);
		else if (cmd[i] == '$')
			cmd = ft_treat_dollars(cmd, &i);
		else if (str[i] == '~')
			cmd = ft_treat_tilde(cmd, &i);
		i++;
	}
	return (cmd);
}

char		*ft_treat_dollars(char *str, int *i)
{
	int		save;
	char	*val;
	char	*tmp;
	char	*tmp_2;
	char	*result;

	save = *i + 1;
	while (str[*i] != 0 && ft_isspace(str[*i]) == 0 && ft_isquote(str[*i]) == 0)
		(*i)++;
	tmp = ft_strsub(str, save, *i - save);
	val = ft_return_path(tmp, g_shell.env);
	free(tmp);
	if (val == NULL)
		return (str);
	result = ft_strsub(str, 0, save);
	tmp_2 = ft_strsub(str, *i, ft_strlen(str) - *i);
	tmp = ft_strjoin(result, val);
	free(result);
	result = ft_strjoin(tmp, tmp_2);
	free(tmp_2);
	free(tmp);
	free(str);
	free(val);
	*i = ft_strlen(tmp) - 1;
	return (result);
}

char		*ft_treat_tilde(char *str, int *i)
{
	char	*tmp;
	char	*tmp_2;
	char	*val;
	char	*path;

	if ((val = ft_return_path("HOME", g_shell.env)) == NULL)
		return (str);
	tmp_2 = ft_strsub(str, 0, *i);
	tmp = ft_strjoin(tmp_2, val);
	free(tmp_2);
	tmp_2 = ft_strsub(str, *i + 1, ft_strlen(str) - (*i + 1));
	path = ft_strjoin(tmp, tmp_2);
	*i = ft_strlen(tmp) - 1;
	free(tmp);
	free(tmp_2);
	free(val);
	free(str);
	return (path);
}
