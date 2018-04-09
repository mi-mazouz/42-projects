/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 13:59:41 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/15 17:18:09 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	ft_exec_env(char **envnt, char **tab, t_list **env, int i)
{
	char	*path;

	ft_free_tab(envnt);
	if (tab[i] != NULL)
	{
		tab = &tab[i];
		if (ft_check_builtins(env, tab) == -1)
		{
			if ((path = ft_set_path(tab, *env)) != NULL)
				ft_fork(tab, path, *env);
		}
		return ;
	}
	ft_print_env(*env);
	ft_list_del_all(env, ft_free_env);
}

static void	ft_change_var_env(char **tab, t_list **env, int i, int j)
{
	char	*var;
	char	*value;

	var = ft_strsub(tab[i], 0, j);
	value = ft_strsub(tab[i], j + 1, ft_strlen(tab[i]) - j);
	ft_setenv(env, var, value);
	free(var);
	free(value);
}

static int	ft_env_u(char **tab, int *i, t_list **env)
{
	if (tab[*i + 1] == NULL)
		return (ft_error("env", ER_ARG));
	else if (ft_strchri(tab[*i + 1], '=') > -1)
		return (ft_error(ER_ENV, tab[*i + 1]));
	ft_unsetenv(env, tab[*i + 1]);
	(*i)++;
	return (0);
}

int			ft_env(char **tab, t_list *env)
{
	char	**environ;
	t_list	*cp;
	int		i;
	int		j;

	i = 1;
	environ = ft_list_in_env(env);
	cp = ft_env_in_list(environ);
	while (tab[i] != NULL)
	{
		if (ft_strcmp(tab[i], "-i") == 0)
			ft_list_del_all(&cp, ft_free);
		else if (ft_strcmp(tab[i], "-u") == 0)
		{
			if (ft_env_u(tab, &i, &cp) != 0)
				return (1);
		}
		else if ((j = ft_strchri(tab[i], '=')) > 0)
			ft_change_var_env(tab, &cp, i, j);
		else
			break ;
		i++;
	}
	ft_exec_env(environ, tab, &cp, i);
	return (1);
}
