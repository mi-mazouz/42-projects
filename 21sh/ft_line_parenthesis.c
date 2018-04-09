/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_parenthesis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 17:02:40 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/12 20:01:31 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	ft_copy_parenthesis_in_line(t_line *parent, t_line *line)
{
	t_list	*ptr;

	ptr = parent->start;
	while (ptr != NULL)
	{
		ft_line_in_list(line, ((t_char *)ptr->data)->c);
		ft_go_to_last(&line->curs);
		ptr = ptr->next;
	}
	ft_list_del_all(&parent->start, ft_free);
	parent->curs = NULL;
}

void		ft_line_parenthesis(t_line *line, t_his *his)
{
	char	buf[7];
	t_line	new_line;

	ft_strclr(buf, 7);
	ft_init_new_line(&new_line);
	while (read(0, buf, 6) > 0)
	{
		if (buf[0] == 10 && buf[1] == 0)
		{
			ft_copy_parenthesis_in_line(&new_line, line);
			return (ft_return(line, his, &g_shell.env));
		}
		else if (ft_isprint(buf[0]) != 1)
			ft_check_touch(&new_line, his, buf);
		else
		{
			ft_line_in_list(&new_line, buf[0]);
			if (new_line.curs->next == NULL)
				ft_put_curs(&new_line);
			else
				ft_insert_char(&new_line);
		}
		ft_strclr(buf, 7);
	}
}
