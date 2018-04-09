/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:59:54 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/27 19:38:56 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_exec_cmd(char **tab, t_env *env)
{
	char	*path;
	char	**environ;

	path = NULL;
	environ = ft_list_in_env(env);
	if (tab[0][0] == '.' || tab[0][0] == '/')
		path = ft_strdup(tab[0]);
	if (path != NULL || (path = ft_other_path(tab[0], env)) != NULL)
	{
		if ((tab[0][0] == '.' || tab[0][0] == '/') && access(path, F_OK) == -1)
		{
			free(path);
			return (ft_error(8, tab[0]));
		}
		if (access(path, X_OK) == -1)
		{
			free(path);
			return (ft_error(4, tab[0]));
		}
		return (ft_fork(path, tab, environ));
	}
	ft_free_tab(environ);
	return (ft_error(2, tab[0]));
}

int		ft_fork(char *path, char **tab, char **environ)
{
	pid_t	father;
	int		i;

	i = 0;
	father = fork();
	if (father == 0)
	{
		if (execve(path, tab, environ) == -1)
		{
			ft_printf("minishell: the file is not an executable.\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (father > 0)
	{
		ft_free_tab(environ);
		free(path);
		wait(&i);
	}
	return (1);
}
