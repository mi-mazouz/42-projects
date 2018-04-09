/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:31:58 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/26 19:59:20 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_command(t_env **env, char **tab)
{
	int i;

	i = 0;
	if (ft_strcmp(tab[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (ft_strcmp(tab[0], "cd") == 0)
		return (ft_cd(*env, tab));
	else if (ft_strcmp(tab[0], "setenv") == 0)
		return (ft_check_setenv(tab, env));
	else if (ft_strcmp(tab[0], "unsetenv") == 0)
	{
		while (tab[++i] != NULL)
			ft_unsetenv(env, tab[i]);
		return (1);
	}
	else if (ft_strcmp(tab[0], "env") == 0)
		return (ft_env(tab, *env));
	return (ft_exec_cmd(tab, *env));
}
