/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 21:28:30 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/27 19:37:30 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cd(t_env *env, char **tab)
{
	int		i;
	char	*path;

	i = ft_parsing_cd(env, tab);
	if (i == -1)
	{
		if (ft_return_path("HOME", env) == NULL)
			return (ft_error(3, tab[0]));
		ft_change_path("OLDPWD", ft_return_path("PWD", env), env);
		ft_change_path("PWD", ft_return_path("HOME", env), env);
		if (access((path = ft_return_path("HOME", env)), X_OK) == -1)
			return (ft_error(4, path));
		chdir(path);
	}
	else if (i == 0)
		return (ft_error(5, tab[0]));
	return (1);
}

int		ft_parsing_cd(t_env *env, char **tab)
{
	int	i;

	i = 1;
	while (tab[i] != NULL)
	{
		if (ft_strcmp(tab[i], "-L") != 0 && ft_strcmp(tab[i], "-P") != 0)
			break ;
		i++;
	}
	if (tab[i] && ft_strcmp(tab[i], "--") == 0)
		i++;
	if (tab[i] == NULL)
		return (-1);
	else if (tab[i + 1] != NULL)
		return (0);
	if (ft_check_path_cd(env, i, tab) == 0)
		return (0);
	return (1);
}

int		ft_check_path_cd(t_env *env, int i, char **tab)
{
	char	*tmp;

	if (ft_strcmp(tab[i], "-") == 0)
		return (ft_cd_less(env));
	if (tab[i][0] == '~')
	{
		tmp = ft_strsub(tab[i], 1, ft_strlen(tab[i]) - 1);
		free(tab[i]);
		tab[i] = ft_strjoin(ft_return_path("HOME", env), tmp);
		free(tmp);
	}
	if (access(tab[i], F_OK) == -1)
		return (ft_error(8, tab[i]));
	if (access(tab[i], X_OK) == -1)
		return (ft_error(4, tab[i]));
	if (chdir(tab[i]) == -1)
		return (ft_error(8, tab[i]));
	ft_change_path("OLDPWD", ft_return_path("PWD", env), env);
	tmp = getcwd(NULL, MAXPATHLEN);
	ft_change_path("PWD", tmp, env);
	free(tmp);
	return (1);
}

int		ft_cd_less(t_env *env)
{
	char	*pwd;
	char	*dir;

	if ((pwd = ft_return_path("PWD", env)) != NULL)
		pwd = ft_strdup(pwd);
	if ((dir = ft_return_path("OLDPWD", env)) != NULL)
		dir = ft_strdup(dir);
	ft_change_path("PWD", dir, env);
	ft_change_path("OLDPWD", pwd, env);
	if (pwd != NULL)
		free(pwd);
	if (access(dir, F_OK) == -1)
		ft_printf("no such file or directory: %s\n", dir);
	else if (access(dir, X_OK) == -1)
		ft_printf("minishell: permission denied: %s\n", dir);
	else if (chdir(dir) == -1)
		ft_printf("no such file or directory: %s\n", dir);
	if (dir != NULL)
		free(dir);
	return (1);
}
