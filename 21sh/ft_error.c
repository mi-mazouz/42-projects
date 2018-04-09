/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:14:48 by MrRobot           #+#    #+#             */
/*   Updated: 2016/06/28 10:51:40 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_error(char *error, char *str)
{
	if (error != NULL)
		ft_putstr_fd(error, g_shell.fd.stderr);
	if (str != NULL)
		ft_putstr_fd(str, g_shell.fd.stderr);
	ft_putchar_fd('\n', g_shell.fd.fd);
	return (-1);
}
