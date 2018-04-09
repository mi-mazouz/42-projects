/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 13:59:41 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/15 17:23:35 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_env(char **tab, t_env *env)
{
	char	**environ;
	t_env	*cp;
	int		i;
	int		j;

	i = 1;
	environ = ft_list_in_env(env);
	ft_env_in_list(&cp, environ);
	while (tab[i] != NULL)
	{
		if (ft_strcmp(tab[i], "-i") == 0)
			ft_free_list(&cp);
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

int		ft_env_u(char **tab, int *i, t_env **env)
{
	if (tab[*i + 1] == NULL)
		return (ft_error(6, NULL));
	else if (ft_strchri(tab[*i + 1], '=') > -1)
		return (ft_error(9, tab[*i + 1]));
	ft_unsetenv(env, tab[*i + 1]);
	(*i)++;
	return (0);
}

void	ft_change_var_env(char **tab, t_env **env, int i, int j)
{
	char	*var;
	char	*value;

	var = ft_strsub(tab[i], 0, j);
	value = ft_strsub(tab[i], j + 1, ft_strlen(tab[i]) - j);
	ft_setenv(env, var, value);
	free(var);
	free(value);
}

void	ft_exec_env(char **envnt, char **tab, t_env **env, int i)
{
	ft_free_tab(envnt);
	if (tab[i] != NULL)
	{
		tab = &tab[i];
		ft_check_command(env, tab);
		return ;
	}
	ft_print_list(*env);
	ft_free_list(env);
}
