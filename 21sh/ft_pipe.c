/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:40:04 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/29 17:03:15 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_valid_path(char *str, t_list *env)
{
	char	**tmp;
	char	**cmd;
	char	*path;

	tmp = ft_strsplit_space(str);
	if (tmp[0] == NULL)
	{
		ft_free_tab(tmp);
		return (ft_error(ER_PARSE, NULL));
	}
	cmd = ft_remove_quote_tab(tmp);
	if (ft_strcmp(cmd[0], "unsetenv") == 0 || ft_strcmp(cmd[0], "env") == 0)
		return (1);
	else if (ft_strcmp(cmd[0], "cd") == 0 || ft_strcmp(cmd[0], "setenv") == 0)
		return (1);
	path = ft_set_path(cmd, env);
	ft_free_tab(tmp);
	ft_free_tab(cmd);
	if (path == NULL)
	{
		free(path);
		return (-1);
	}
	free(path);
	return (1);
}

int		ft_check_valid_cmd(t_tree *tree, t_list *env)
{
	if (tree->left->type == TYPE_P)
	{
		if (ft_check_valid_cmd(tree->left, env) == -1)
			return (-1);
	}
	else
	{
		if (ft_valid_path(tree->left->cmd, env) == -1)
			return (-1);
	}
	if (ft_valid_path(tree->right->cmd, env) == -1)
		return (-1);
	return (1);
}

void	ft_pipe(t_tree *tree, t_list **env)
{
	int		fd[2];
	char	*cmd;
	pid_t	father;

	pipe(fd);
	father = fork();
	if (father == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		cmd = tree->left->cmd;
		if (tree->left->type == TYPE_P)
			ft_pipe(tree->left, env);
		ft_chr_redirect(cmd) ? ft_redirect(cmd, env, 1) : ft_no_fork(cmd, env);
	}
	else if (father > 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		cmd = tree->right->cmd;
		ft_chr_redirect(cmd) ? ft_redirect(cmd, env, 1) : ft_no_fork(cmd, env);
	}
}

void	ft_treat_pipe(t_tree *tree, t_list **env)
{
	int		sig;
	pid_t	father;

	if (ft_check_valid_cmd(tree, *env) == -1)
		return ;
	father = fork();
	if (father == 0)
	{
		ft_pipe(tree, env);
		exit(EXIT_SUCCESS);
	}
	else if (father > 0)
	{
		signal(SIGINT, SIG_IGN);
		wait(&sig);
		if (WIFEXITED(sig) == 0)
			ft_signal_2(sig, NULL);
	}
}
