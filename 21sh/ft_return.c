/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:26:34 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/07 20:04:14 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_return(t_line *line, t_his *his, t_list **env)
{
	if (line->start != NULL)
	{
		if (ft_check_parenthesis(line->start) == 1)
			ft_go_cmd(line, his, env);
		else
		{
			ft_list_add_last(line->start, ft_new_link_line('\n'));
			ft_go_to_last(&line->curs);
			ft_line_parenthesis(line, his);
		}
	}
	else
		ft_print_prompt(1);
	g_shell.his.go = 0;
}

void	ft_go_cmd(t_line *line, t_his *his, t_list **env)
{
	char	*tmp;
	char	*cmd;
	t_tree	*tree;

	tmp = ft_list_in_line(line->start);
	cmd = ft_strtrim_separator(tmp);
	ft_putchar_fd('\n', g_shell.fd.fd);
	if (cmd[0] == 0)
		free(cmd);
	else
	{
		tree = ft_build_tree(cmd);
		ft_list_in_his(his, line->start);
		ft_dispatch_cmd(tree, env);
		ft_tree_del_all(&tree);
	}
	free(tmp);
	ft_list_del_all(&line->start, ft_free);
	line->curs = NULL;
	ft_print_prompt(0);
}
