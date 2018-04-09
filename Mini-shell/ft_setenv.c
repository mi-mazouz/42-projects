/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:41:22 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/15 17:24:13 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_setenv(char **tab, t_env **env)
{
	if (tab[1] != NULL && tab[2] != NULL && tab[3] != NULL)
		return (ft_error(5, tab[0]));
	else if (tab[1] && ft_strchri(tab[1], '=') > -1)
		return (ft_error(10, tab[0]));
	else if (tab[1])
		return (ft_setenv(env, tab[1], tab[2]));
	return (1);
}

int		ft_setenv(t_env **env, char *var, char *value)
{
	t_env	*curs;

	curs = *env;
	if (*env == NULL)
		*env = ft_make_setenv(var, value);
	while (curs != NULL)
	{
		if (ft_strcmp(var, curs->var) == 0)
		{
			if (curs->value != NULL)
				free(curs->value);
			if (value != NULL)
				curs->value = ft_strdup(value);
			else
				curs->value = NULL;
			return (1);
		}
		else if (curs->next == NULL)
			curs->next = ft_make_setenv(var, value);
		curs = curs->next;
	}
	return (1);
}

t_env	*ft_make_setenv(char *var, char *value)
{
	t_env *ptr;

	ptr = malloc(sizeof(t_env));
	ptr->var = ft_strdup(var);
	if (value != NULL)
		ptr->value = ft_strdup(value);
	else
		ptr->value = NULL;
	ptr->next = NULL;
	return (ptr);
}
