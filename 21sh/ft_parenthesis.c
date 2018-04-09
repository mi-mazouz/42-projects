/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parenthesis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 09:04:10 by MrRobot           #+#    #+#             */
/*   Updated: 2016/07/14 19:28:49 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_put_parenthesis(char c)
{
	ft_putchar_fd('\n', g_shell.fd.fd);
	if (c == 34)
		ft_putstr_fd("dquote> ", g_shell.fd.fd);
	else if (c == 40)
		ft_putstr_fd("subsh> ", g_shell.fd.fd);
	else if (c == 123)
		ft_putstr_fd("crush> ", g_shell.fd.fd);
	else if (c == 91)
		ft_putstr_fd("hook> ", g_shell.fd.fd);
	else if (c == 39)
		ft_putstr_fd("quote> ", g_shell.fd.fd);
	else if (c == 96)
		ft_putstr_fd("bquote> ", g_shell.fd.fd);
	return (0);
}

int		ft_check_close_quote(t_list *curs, char c)
{
	char chr;

	while (curs != NULL)
	{
		chr = ((t_char *)curs->data)->c;
		if (chr == c)
			return (1);
		curs = curs->next;
	}
	return (0);
}

int		ft_check_close_parenthesis(t_list *curs, char c)
{
	char	chr;
	int		i;

	i = 0;
	while (curs != NULL)
	{
		chr = ((t_char *)curs->data)->c;
		if (chr == c + 2 || (c == 40 && chr == 41))
			return (1);
		else if (chr == 34 || chr == 39 || chr == 96)
		{
			if (ft_check_close_quote(curs->next, chr) == 0)
				ft_go_to_last(&curs);
			else
			{
				curs = curs->next;
				while (((t_char *)curs->data)->c != chr)
					curs = curs->next;
			}
		}
		curs = curs->next;
	}
	return (0);
}

int		ft_check_parenthesis(t_list *start)
{
	char	chr;

	while (start != NULL)
	{
		chr = ((t_char *)start->data)->c;
		if (chr == 39 || chr == 34 || chr == 96)
		{
			if (ft_check_close_quote(start->next, chr) == 0)
				return (ft_put_parenthesis(chr));
			start = start->next;
			while (((t_char *)start->data)->c != chr)
				start = start->next;
		}
		else if (chr == 123 || chr == 91 || chr == 40)
		{
			if (ft_check_close_parenthesis(start->next, chr) == 0)
				return (ft_put_parenthesis(chr));
		}
		start = start->next;
	}
	return (1);
}
