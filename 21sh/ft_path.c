/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:38:59 by MrRobot           #+#    #+#             */
/*   Updated: 2016/08/31 16:52:59 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_path_env(char *cmd, t_list *env)
{
	char	*path;
	char	*tmp;
	char	**var;
	int		i;

	i = -1;
	if ((path = ft_return_path("PATH", env)) == NULL)
		return (NULL);
	var = ft_strsplit(path, ':');
	free(path);
	while (var[++i] != NULL)
	{
		tmp = ft_strjoin(var[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			ft_free_tab(var);
			return (path);
		}
		free(path);
	}
	ft_free_tab(var);
	return (NULL);
}

char	*ft_return_path(char *chr, t_list *env)
{
	t_list	*curs;

	curs = env;
	while (curs != NULL)
	{
		if (ft_strcmp(((t_env *)curs->data)->var, chr) == 0)
			return (ft_strdup(((t_env *)curs->data)->val));
		curs = curs->next;
	}
	return (NULL);
}

char	*ft_set_path(char **tab, t_list *env)
{
	char	*path;

	path = NULL;
	if (tab[0][0] == '.' || tab[0][0] == '/')
		path = ft_strdup(tab[0]);
	if (path != NULL || (path = ft_path_env(tab[0], env)) != NULL)
	{
		if ((tab[0][0] == '.' || tab[0][0] == '/') && access(path, F_OK) == -1)
		{
			free(path);
			ft_error(ER_CD, tab[0]);
			return (NULL);
		}
		if (access(path, X_OK) == -1)
		{
			free(path);
			ft_error(ER_PERM, tab[0]);
			return (NULL);
		}
		return (path);
	}
	ft_error(ER_CMD, tab[0]);
	return (NULL);
}

void	ft_change_path(char *var, char *new_val, t_list *env)
{
	t_list	*curs;

	curs = env;
	while (curs != NULL)
	{
		if (ft_strcmp(((t_env *)curs->data)->var, var) == 0)
		{
			if (new_val != NULL)
			{
				free(((t_env *)curs->data)->val);
				((t_env *)curs->data)->val = ft_strdup(new_val);
			}
		}
		curs = curs->next;
	}
}
