/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 17:02:12 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/05 18:57:28 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_dup_fd(t_fd *fd)
{
	if (fd->stderr == -1)
		close(STDERR_FILENO);
	else if (fd->stderr != 2)
		dup2(fd->stderr, STDERR_FILENO);
	if (fd->stdout == -1)
		close(STDOUT_FILENO);
	else if (fd->stdout != 1)
		dup2(fd->stdout, STDOUT_FILENO);
	if (fd->stdin == -1)
		close(STDIN_FILENO);
	else if (fd->stdin != 0)
		dup2(fd->stdin, STDIN_FILENO);
}

void	ft_close_fd(t_fd *fd)
{
	if (fd->stderr != 2)
		fd->stderr = 2;
	if (fd->stdout != 1)
		fd->stdout = 1;
	if (fd->stdin != 0)
		fd->stdin = 0;
}

int		ft_open_fd(char *str, int j, char c, int test)
{
	char	*file;
	int		fd;

	if (str[j + 2] == '&' || (test == 1 && str[j + 3] == '&'))
	{
		if (test == 1)
			str[j + 3] = ' ';
		else
			str[j + 2] = ' ';
		j++;
	}
	if ((file = ft_set_file(str, j + 2)) == NULL)
		return (-3);
	if (test == 1)
		fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else if (test == 2)
		fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_error(ER_CD, file));
	ft_change_fd(c, test, fd);
	free(file);
	return (1);
}

int		ft_change_fd(char c, int test, int fd)
{
	if (c == '0' || (test == 3 && c != '1' && c != '2'))
		g_shell.fd.stdin = fd;
	if (c == '1' || ((test == 1 || test == 2) && c != '0' && c != '2'))
		g_shell.fd.stdout = fd;
	if (c == '2')
		g_shell.fd.stderr = fd;
	else if (c == '&')
	{
		g_shell.fd.stdin = fd;
		g_shell.fd.stdout = fd;
		g_shell.fd.stderr = fd;
	}
	return (-3);
}
