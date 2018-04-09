/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:57:22 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/30 10:09:29 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_count_w(char const *s, char c, char u)
{
	int	i;
	int	mots;

	mots = 0;
	i = 0;
	while (s[i])
	{
		while ((s[i] == c || s[i] == u) && (s[i + 1] == c || s[i + 1] == u))
			i++;
		if (s[i] == c || s[i] == u)
			i++;
		while ((s[i] != c && s[i] != u) && s[i] != 0)
			i++;
		if (s[i] == 0 && (s[i - 1] != c && s[i - 1] != u))
			mots++;
		if (s[i] == 0)
			mots--;
		mots++;
	}
	return (mots);
}

static char		**ft_strsplif(char const *s, char c)
{
	int		i;
	int		m;
	int		st;
	int		len;
	char	**tab;

	i = 0;
	st = 0;
	m = ft_count_w(s, c, '\t');
	if (!(tab = (char **)malloc(sizeof(char *) * (m + 1))))
		return (NULL);
	tab[m] = NULL;
	while (i < m)
	{
		while (s[st] && (s[st] == c || s[st] == '\t'))
			st++;
		len = 0;
		while (s[st + len] != c && s[st + len] != '\t' && s[st + len] != 0)
			len++;
		tab[i] = ft_strsub(s, st, len);
		st = st + len;
		i++;
	}
	return (tab);
}

void			ft_exec_minishell(char *line, int argc, t_env *env_list)
{
	char	**tab;
	char	**cmd;

	while (ft_get_next_line(1, &line) == 1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, ft_signal_2);
		tab = ft_strsplit(line, ';');
		free(line);
		argc = 0;
		while (tab[argc] != NULL)
		{
			cmd = ft_strsplif(tab[argc], ' ');
			if (cmd[0] != NULL)
				ft_check_command(&env_list, cmd);
			argc++;
			ft_free_tab(cmd);
		}
		line = NULL;
		ft_free_tab(tab);
		signal(SIGINT, ft_signal);
		ft_printf("%sMr.Robot%s--> %s", RED, BLUE, STOP);
	}
}

int				main(int argc, char **argv, char **env)
{
	t_env	*env_list;

	argv[1] = NULL;
	ft_env_in_list(&env_list, env);
	ft_printf("%sMr.Robot%s--> %s", RED, BLUE, STOP);
	signal(SIGINT, ft_signal);
	signal(SIGQUIT, SIG_IGN);
	ft_exec_minishell(argv[1], argc, env_list);
	return (0);
}
