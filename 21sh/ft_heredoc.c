/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 20:24:03 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/26 11:07:07 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	ft_read_heredoc(int fd, char *word)
{
	char	buf[7];
	char	*str;

	ft_strclr(buf, 7);
	str = NULL;
	while (read(0, buf, 6) > 0)
	{
		if ((buf[0] == 10 && buf[1] == 0) || (buf[0] == 4 && buf[1] == 0))
		{
			if (buf[0] == 4 || (str != NULL && ft_strcmp(str, word) == 0))
			{
				str != NULL ? free(str) : (0);
				return ;
			}
			ft_putstr_fd("\nheredoc> ", g_shell.fd.stdout);
			str != NULL ? ft_putendl_fd(str, fd) : (0);
			str != NULL ? ft_strdel(&str) : (0);
		}
		else if (ft_isprint(buf[0]) == 1)
		{
			ft_putchar_fd(buf[0], g_shell.fd.stdout);
			str = ft_str_add_last(str, buf[0]);
		}
		ft_strclr(buf, 7);
	}
}

void		ft_heredoc(char *str, int i)
{
	char	*word;
	int		fd;

	str[i++] = ' ';
	str[i++] = ' ';
	ft_putstr_fd("heredoc> ", g_shell.fd.fd);
	signal(SIGINT, SIG_IGN);
	word = ft_set_file(str, i);
	fd = open("/tmp/heredoc.txt", O_RDWR | O_TRUNC | O_CREAT, 0644);
	ft_read_heredoc(fd, word);
	ft_putchar_fd('\n', g_shell.fd.stdout);
	close(fd);
	fd = open("/tmp/heredoc.txt", O_RDONLY);
	free(word);
	g_shell.fd.stdin = fd;
}
