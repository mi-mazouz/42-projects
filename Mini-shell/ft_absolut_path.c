/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolut_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 23:36:37 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/27 19:21:54 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_other_path(char *cmd, t_env *env)
{
	char	*path;
	char	*tmp;
	char	**var;
	int		i;

	i = -1;
	if ((path = ft_return_path("PATH", env)) == NULL)
		return (NULL);
	var = ft_strsplit(path, ':');
	while (var[++i] != NULL)
	{
		tmp = ft_strjoin(var[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			break ;
		free(path);
	}
	if (var[i] == NULL)
	{
		ft_free_tab(var);
		return (NULL);
	}
	ft_free_tab(var);
	return (path);
}
