/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 08:23:41 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/29 17:03:28 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_treat_cmd(char *str, t_list **env)
{
	char			**tmp;
	char			**cmd;
	char			*path;
	struct termios	term_set;

	tmp = ft_strsplit_space(str);
	cmd = ft_remove_quote_tab(tmp);
	if (cmd[0] != NULL)
	{
		if (ft_chr_redirect(str) == 0)
		{
			if (ft_check_builtins(env, cmd) == -1)
			{
				tcsetattr(0, TCSADRAIN, &g_shell.term_restore);
				if ((path = ft_set_path(cmd, *env)) != NULL)
					ft_fork(cmd, path, *env);
				ft_modif_term(&term_set, 0);
			}
		}
		else
			ft_redirect(str, env, 0);
	}
	ft_free_tab(tmp);
	ft_free_tab(cmd);
}

void	ft_dispatch_cmd(t_tree *tree, t_list **env)
{
	if (tree != NULL)
	{
		if (tree->type == TYPE_P)
			ft_treat_pipe(tree, env);
		else if (tree->type == TYPE_C)
			ft_treat_cmd(tree->cmd, env);
		else if (tree->type == TYPE_V)
		{
			ft_dispatch_cmd(tree->left, env);
			ft_dispatch_cmd(tree->right, env);
		}
	}
}

int		ft_check_builtins(t_list **env, char **tab)
{
	int i;

	i = 0;
	if (ft_strcmp(tab[0], "cd") == 0)
		ft_cd(*env, tab);
	else if (ft_strcmp(tab[0], "setenv") == 0)
		ft_check_setenv(tab, env);
	else if (ft_strcmp(tab[0], "unsetenv") == 0)
	{
		while (tab[++i] != NULL)
			ft_unsetenv(env, tab[i]);
	}
	else if (ft_strcmp(tab[0], "env") == 0)
		ft_env(tab, *env);
	else if (ft_strcmp(tab[0], "echo") == 0)
		ft_echo(tab);
	else if (ft_strcmp(tab[0], "exit") == 0)
		ft_exit(&g_shell.term_restore, 1);
	else
		return (-1);
	return (1);
}
