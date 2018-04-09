/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:37:13 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/15 17:18:25 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_print_env(t_list *env)
{
	t_list	*curs;

	curs = env;
	if (g_shell.fd.stdout == -1)
		return ;
	while (curs != NULL)
	{
		ft_putstr_fd(((t_env *)curs->data)->var, g_shell.fd.stdout);
		ft_putchar_fd('=', g_shell.fd.stdout);
		ft_putendl_fd(((t_env *)curs->data)->val, g_shell.fd.stdout);
		curs = curs->next;
	}
}

char	**ft_list_in_env(t_list *env_list)
{
	char	*val;
	char	**env;
	t_list	*curs;
	char	*tmp;
	int		i;

	i = 0;
	curs = env_list;
	while (env_list != NULL)
	{
		i++;
		env_list = env_list->next;
	}
	env = ft_tabnew(i);
	i = 0;
	while (curs != NULL)
	{
		val = ((t_env *)curs->data)->val;
		tmp = ft_strjoin(((t_env *)curs->data)->var, "=");
		env[i] = ft_strjoin(tmp, val ? val : "");
		free(tmp);
		curs = curs->next;
		i++;
	}
	return (env);
}

t_list	*ft_env_in_list(char **env)
{
	int		i;
	t_list	*env_list;

	i = 1;
	if (env[0] == NULL)
		return (NULL);
	env_list = ft_list_add_new(ft_new_link_env(env[0]));
	while (env[i] != NULL)
	{
		ft_list_add_last(env_list, ft_new_link_env(env[i]));
		i++;
	}
	return (env_list);
}

t_env	*ft_new_link_env(char *str)
{
	t_env	*link;
	int		i;

	i = ft_strchri(str, '=');
	link = malloc(sizeof(t_env));
	link->var = ft_strsub(str, 0, i);
	link->val = ft_strsub(str, i + 1, ft_strlen(str) - i - 1);
	return (link);
}
