/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:20:36 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/29 17:02:30 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_chr_redirect(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '"' || str[i] == '\'')
			ft_jump_quote(str, &i);
		else if (str[i] == '<' || str[i] == '>')
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_valid_redirect(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '"' || str[i] == '\'')
			ft_jump_quote(str, &i);
		else if (str[i] == '>' || str[i] == '<')
		{
			if (ft_count_redirect(str, &i) == -1)
				return (-1);
			continue ;
		}
		i++;
	}
	return (1);
}

int		ft_dispatch_redirect(char *str)
{
	int		fd;
	int		i;

	i = 0;
	fd = 1;
	while (str[i] != 0)
	{
		if (str[i] == '"' || str[i] == '\'')
			ft_jump_quote(str, &i);
		else if (str[i] == '>' && str[i + 1] == '>')
			fd = ft_check_aggregations(str, i, 1);
		else if (str[i] == '<' && str[i + 1] == '<')
			ft_heredoc(str, i);
		else if (str[i] == '>')
			fd = ft_check_aggregations(str, i, 2);
		else if (str[i] == '<')
			fd = ft_check_aggregations(str, i, 3);
		i++;
	}
	return (fd);
}

int		ft_count_redirect(char *s, int *i)
{
	int	j;
	int	rd;

	rd = 0;
	while (s[*i] != 0 && (ft_isspace(s[*i]) || s[*i] == '>' || s[*i] == '<'))
	{
		if (s[*i] == '>' || s[*i] == '<')
		{
			j = *i;
			rd++;
		}
		(*i)++;
	}
	if ((s[*i] == 0 || rd > 2) || (rd == 2 && s[j - 1] != s[j]))
		return (-1);
	else if (s[*i + 1] == 0 && s[*i] == '&')
		return (-1);
	return (1);
}

int		ft_redirect(char *str, t_list **env, int test)
{
	int		fd;
	char	*path;
	char	**tmp;
	char	**cmd;

	if (ft_check_valid_redirect(str) == -1)
		return (ft_error(ER_REDIR, NULL));
	if ((fd = ft_dispatch_redirect(str)) == -1)
		return (0);
	if (test == 1)
	{
		ft_no_fork(str, env);
		return (1);
	}
	tmp = ft_strsplit_space(str);
	cmd = ft_remove_quote_tab(tmp);
	path = ft_set_path(cmd, *env);
	if (path != NULL)
		ft_fork(cmd, path, *env);
	else
		ft_close_fd(&g_shell.fd);
	ft_free_tab(tmp);
	ft_free_tab(cmd);
	return (1);
}
