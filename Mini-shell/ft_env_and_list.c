/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_and_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 23:06:05 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/15 17:23:57 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_list(t_env *env)
{
	t_env	*curs;

	curs = env;
	while (curs != NULL)
	{
		ft_printf("%s=", curs->var);
		if (curs->value != NULL)
			ft_putendl(curs->value);
		else if (curs->next == NULL || curs->value == NULL)
			ft_putchar('\n');
		curs = curs->next;
	}
}

char	**ft_list_in_env(t_env *env_list)
{
	char	**env;
	t_env	*curs;
	char	*tmp;
	int		i;

	i = 0;
	curs = env_list;
	while (env_list != NULL)
	{
		i++;
		env_list = env_list->next;
	}
	env = (char **)malloc(sizeof(char *) * (i + 1));
	env[i] = NULL;
	i = 0;
	while (curs != NULL)
	{
		tmp = ft_strjoin(curs->var, "=");
		env[i] = ft_strjoin(tmp, curs->value ? curs->value : "");
		free(tmp);
		curs = curs->next;
		i++;
	}
	return (env);
}

void	ft_env_in_list(t_env **env_list, char **env)
{
	int		i;
	t_env	*ptr;

	i = 1;
	if (env[0] == NULL)
	{
		*env_list = NULL;
		return ;
	}
	*env_list = ft_make_list(env[0]);
	ptr = *env_list;
	while (env[i] != NULL)
	{
		ptr->next = ft_make_list(env[i]);
		ptr = ptr->next;
		i++;
	}
}

t_env	*ft_make_list(char *str)
{
	t_env	*ptr;
	int		i;

	i = ft_strchri(str, '=');
	ptr = malloc(sizeof(t_env));
	ptr->next = NULL;
	ptr->var = ft_strsub(str, 0, i);
	ptr->value = ft_strsub(str, i + 1, ft_strlen(str) - i - 1);
	return (ptr);
}
