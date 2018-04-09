/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 09:48:55 by MrRobot           #+#    #+#             */
/*   Updated: 2016/07/22 14:50:34 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_free(void *del)
{
	free(del);
}

void	ft_free_env(void *del)
{
	free(((t_env *)del)->var);
	free(((t_env *)del)->val);
	free(del);
}

void	ft_free_tabulation(t_tab *tab)
{
	free(tab->file);
	free(tab->path);
	free(tab->abrvt);
	tab->abrvt = NULL;
	tab->file = NULL;
	tab->path = NULL;
}

void	ft_tree_del_all(t_tree **tree)
{
	if (*tree != NULL)
	{
		ft_tree_del_all(&(*tree)->left);
		ft_tree_del_all(&(*tree)->right);
		if ((*tree)->cmd != NULL)
			free((*tree)->cmd);
		free(*tree);
	}
}

void	ft_free_cut(t_line *line, t_list **ptr)
{
	if ((*ptr)->prev == NULL && (*ptr)->next == NULL)
	{
		ft_list_del_last_one(&line->start, ft_free);
		*ptr = NULL;
	}
	else if ((*ptr)->prev == NULL && (*ptr)->next != NULL)
	{
		*ptr = (*ptr)->next;
		ft_list_del_first(&line->start, ft_free);
	}
	else if ((*ptr)->next == NULL && (*ptr)->prev != NULL)
	{
		ft_list_del_last(&line->start, ft_free);
		*ptr = (*ptr)->next;
	}
	else
	{
		ft_list_del(*ptr, ft_free);
		*ptr = (*ptr)->next;
	}
}
