/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 20:37:44 by MrRobot           #+#    #+#             */
/*   Updated: 2016/07/10 15:32:50 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_tree		*ft_build_tree(char *cmd)
{
	t_tree	*tree;
	int		i;

	tree = ft_new_link_tree();
	if ((i = ft_find_separator(cmd, ';', 0)) == -1)
	{
		tree->type = TYPE_C;
		tree->cmd = ft_strdup(cmd);
		free(cmd);
		return (tree);
	}
	if (cmd[i] == ';')
		tree->type = TYPE_V;
	else if (cmd[i] == '|')
		tree->type = TYPE_P;
	tree->left = ft_build_tree(ft_strsub(cmd, 0, i));
	tree->right = ft_build_tree(ft_strdup(cmd + i + 1));
	free(cmd);
	return (tree);
}

t_tree		*ft_new_link_tree(void)
{
	t_tree	*tree;

	tree = malloc(sizeof(t_tree));
	tree->right = NULL;
	tree->left = NULL;
	tree->cmd = NULL;
	tree->type = -1;
	return (tree);
}
