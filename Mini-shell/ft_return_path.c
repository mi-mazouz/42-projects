/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:38:59 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/27 19:22:56 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_return_path(char *chr, t_env *env)
{
	t_env	*curs;

	curs = env;
	while (curs != NULL)
	{
		if (ft_strcmp(curs->var, chr) == 0)
			return (curs->value);
		curs = curs->next;
	}
	return (NULL);
}

void	ft_change_path(char *var, char *new_value, t_env *env)
{
	t_env	*curs;

	curs = env;
	while (curs != NULL)
	{
		if (ft_strcmp(curs->var, var) == 0)
		{
			if (new_value != NULL)
			{
				free(curs->value);
				curs->value = ft_strdup(new_value);
			}
		}
		curs = curs->next;
	}
}
