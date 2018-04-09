/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:45:05 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/26 20:13:27 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_unsetenv(t_env **env, char *var)
{
	t_env	*curs;
	t_env	*ptr;

	curs = *env;
	if (ft_unsetenv_one(env, var) == 1)
		return (1);
	while (curs != NULL)
	{
		if (curs->next && ft_strcmp(var, curs->next->var) == 0)
		{
			free(curs->next->value);
			free(curs->next->var);
			ptr = curs->next->next;
			free(curs->next);
			curs->next = ptr;
			break ;
		}
		curs = curs->next;
	}
	return (1);
}

int		ft_unsetenv_one(t_env **env, char *var)
{
	t_env	*curs;

	if (*env && ft_strcmp(var, (*env)->var) == 0)
	{
		curs = (*env)->next;
		free((*env)->value);
		free((*env)->var);
		free(*env);
		*env = curs;
		return (1);
	}
	return (0);
}
