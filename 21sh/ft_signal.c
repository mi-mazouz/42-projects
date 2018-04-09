/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:29:32 by MrRobot           #+#    #+#             */
/*   Updated: 2016/08/31 12:35:04 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_signal(int test)
{
	test = 0;
	if (g_shell.line.start != NULL)
		ft_list_del_all(&g_shell.line.start, ft_free);
	ft_print_prompt(1);
}

void	ft_signal_2(int status, char *path)
{
	if (WIFSIGNALED(status) > 0)
	{
		if (WTERMSIG(status) == SIGSEGV)
			ft_error(ER_SEG, path);
		else if (WTERMSIG(status) == SIGTERM)
			ft_error(ER_KILL, path);
		else if (WTERMSIG(status) == SIGINT)
		{
			if (g_shell.line.start != NULL)
				ft_list_del_all(&g_shell.line.start, ft_free);
			ft_putchar_fd('\n', g_shell.fd.fd);
		}
	}
}
