/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:14:48 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/27 19:40:01 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_error(int error, char *str)
{
	if (error == 2)
		ft_printf("minishell: command not found: %s\n", str);
	else if (error == 3)
		ft_printf("%s: can't change to home directory.\n", str);
	else if (error == 4)
		ft_printf("minishell: permission denied: %s\n", str);
	else if (error == 5)
		ft_printf("%s: too many arguments.\n", str);
	else if (error == 6)
		ft_printf("env: option requires an argument.\n");
	else if (error == 7)
		ft_printf("env: illegal option -- %s\n");
	else if (error == 8)
		ft_printf("no such file or directory: %s\n", str);
	else if (error == 9)
		ft_printf("env: unsetenv %s: Invalid argiment.\n", str);
	else if (error == 10)
		ft_printf("setenv: Variable name contain '=' characters.\n", str);
	return (1);
}
