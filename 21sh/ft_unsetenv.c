/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:45:05 by MrRobot           #+#    #+#             */
/*   Updated: 2016/07/22 16:41:25 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	ft_unsetenv_one(t_list **env, char *var)
{
	t_list	*curs;

	if (*env != NULL && ft_strcmp(var, ((t_env *)(*env)->data)->var) == 0)
	{
		curs = (*env)->next;
		free(((t_env *)(*env)->data)->val);
		free(((t_env *)(*env)->data)->var);
		free(*env);
		*env = curs;
		return (1);
	}
	return (0);
}

int			ft_unsetenv(t_list **env, char *var)
{
	t_list	*curs;
	t_list	*ptr;

	curs = *env;
	if (ft_unsetenv_one(env, var) == 1)
		return (1);
	while (curs != NULL)
	{
		if (curs->next && ft_strcmp(var, ((t_env *)curs->next->data)->var) == 0)
		{
			ptr = curs->next->next;
			ft_free_env(curs->next->data);
			curs->next = ptr;
			break ;
		}
		curs = curs->next;
	}
	return (1);
}
