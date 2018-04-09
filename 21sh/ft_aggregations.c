/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aggregations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 14:58:31 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/01 21:12:29 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	ft_echange_fd_2(char c, char d)
{
	if (c == '0')
	{
		if (d == '1')
			g_shell.fd.stdin = g_shell.fd.stdout;
		else if (d == '2')
			g_shell.fd.stdin = g_shell.fd.stderr;
		else
			g_shell.fd.stdin = -1;
	}
	else if (d == '-')
	{
		g_shell.fd.stdin = -1;
		g_shell.fd.stderr = -1;
		g_shell.fd.stdout = -1;
	}
}

static int	ft_echange_fd(char c, char d)
{
	if (c == '2')
	{
		if (d == '0')
			g_shell.fd.stderr = g_shell.fd.stdout;
		else if (d == '1')
			g_shell.fd.stderr = g_shell.fd.stdout;
		else
			g_shell.fd.stderr = -1;
	}
	else if (c == '1')
	{
		if (d == '0')
			g_shell.fd.stdout = g_shell.fd.stdin;
		else if (d == '2')
			g_shell.fd.stdout = g_shell.fd.stderr;
		else
			g_shell.fd.stdout = -1;
	}
	else
		ft_echange_fd_2(c, d);
	return (-3);
}

int			ft_check_aggregations(char *str, int i, int test)
{
	char	c;
	char	d;
	int		j;

	j = i - 1;
	str[i++] = ' ';
	if (str[i] == '>')
		str[i++] = ' ';
	if (ft_isdigit(str[j]) == 1)
		c = str[j];
	else
		c = str[i];
	if (str[j] == '2' || str[j] == '1' || str[j] == '0' || str[j] == '&')
		str[j] = ' ';
	if (str[i] == '&' && (str[i + 1] == '-' || str[i + 1] == '0' ||
		str[i + 1] == '1' || str[i + 1] == '2'))
	{
		str[i] = ' ';
		d = str[i + 1];
		str[i + 1] = ' ';
		return (ft_echange_fd(c, d));
	}
	else
		return (ft_open_fd(str, j, c, test));
}
