/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:41:22 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/15 17:18:42 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_setenv(t_list **env, char *var, char *val)
{
	t_list	*curs;

	curs = *env;
	if (*env == NULL)
		*env = ft_list_add_new(ft_new_link_setenv(var, val));
	while (curs != NULL)
	{
		if (ft_strcmp(var, ((t_env *)curs->data)->var) == 0)
		{
			if (((t_env *)curs->data)->val != NULL)
				free(((t_env *)curs->data)->val);
			if (val != NULL)
				((t_env *)curs->data)->val = ft_strdup(val);
			else
				((t_env *)curs->data)->val = NULL;
			return (1);
		}
		else if (curs->next == NULL)
			ft_list_add_last(curs, ft_new_link_setenv(var, val));
		curs = curs->next;
	}
	return (1);
}

int		ft_check_setenv(char **tab, t_list **env)
{
	if (tab[1] != NULL && tab[2] != NULL && tab[3] != NULL)
		return (ft_error(tab[0], ER_ARG));
	else if (tab[1] && ft_strchri(tab[1], '=') > -1)
		return (ft_error(ER_SETENV, NULL));
	else if (tab[1])
		return (ft_setenv(env, tab[1], tab[2]));
	else
		return (ft_error("setenv", ER_ARG));
}

t_env	*ft_new_link_setenv(char *var, char *val)
{
	t_env *new;

	new = malloc(sizeof(t_env));
	new->var = ft_strdup(var);
	if (val != NULL)
		new->val = ft_strdup(val);
	else
		new->val = NULL;
	return (new);
}
