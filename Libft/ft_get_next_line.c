/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 16:30:35 by mimazouz          #+#    #+#             */
/*   Updated: 2017/01/15 17:16:51 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_get	*ft_new_link(int const fd, t_get *next)
{
	t_get	*new;

	new = malloc(sizeof(*new));
	if (new)
	{
		if (next == NULL)
			new->next = new;
		else
			new->next = next;
		new->fd = fd;
		new->save = NULL;
	}
	return (new);
}

static	void	ft_check_link(int const fd, t_get **link, int test_2, int oct)
{
	t_get	*new;

	if (test_2 == 0)
	{
		(*link)->save = ft_strdup((*link)->buff);
		ft_strclr((*link)->buff, BUFF_SIZE + 1);
		oct = read((*link)->fd, (*link)->buff, BUFF_SIZE);
		return ;
	}
	new = *link;
	if (*link == NULL)
	{
		*link = ft_new_link(fd, NULL);
		return ;
	}
	while (new->next != *link && new->fd != fd)
		new = new->next;
	if (new->fd != fd)
	{
		new->next = ft_new_link(fd, new->next);
		*link = new->next;
		return ;
	}
	*link = new;
}

static	int		ft_back_slash_in_buff(char **line, t_get *link, int test)
{
	char	*tmp;
	int		i;

	if (test == 0)
	{
		if (link->save[0] != '\0')
		{
			*line = link->save;
			link->save = NULL;
			return (1);
		}
		return (0);
	}
	i = ft_strchri(link->buff, '\n');
	if (link->save != NULL)
	{
		tmp = ft_strsub(link->buff, 0, i);
		*line = ft_strjoin(link->save, tmp);
		free(tmp);
		free(link->save);
	}
	else
		*line = ft_strsub(link->buff, 0, i);
	link->save = ft_strdup(link->buff + i + 1);
	return (1);
}

static	int		ft_read_buff(int const fd, t_get **link, char **line)
{
	int		oct;
	char	*tmp;

	oct = read((*link)->fd, (*link)->buff, BUFF_SIZE);
	if (oct == -1 || ((*link)->save == NULL && oct == 0))
		return (oct);
	while (oct > 0 && ft_strchri((*link)->buff, '\n') == -1)
	{
		if ((*link)->save == NULL)
			ft_check_link(fd, link, 0, oct);
		else
		{
			tmp = ft_strjoin((*link)->save, (*link)->buff);
			free((*link)->save);
			(*link)->save = tmp;
			ft_strclr((*link)->buff, BUFF_SIZE + 1);
			oct = read((*link)->fd, (*link)->buff, BUFF_SIZE);
		}
	}
	if (oct == 0 && ((*link)->save) != NULL)
		return (ft_back_slash_in_buff(line, *link, 0));
	else
		return (ft_back_slash_in_buff(line, *link, 1));
}

int				ft_get_next_line(int const fd, char **line)
{
	static	t_get	*link = NULL;
	char			*tmp;
	int				i;

	i = 0;
	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	ft_check_link(fd, &link, 1, 42);
	ft_strclr(link->buff, BUFF_SIZE + 1);
	if (link->save != NULL && (i = ft_strchri(link->save, '\n')) != -1)
	{
		*line = ft_strsub(link->save, 0, i);
		tmp = ft_strdup(link->save + i + 1);
		free(link->save);
		link->save = tmp;
	}
	else
		return (ft_read_buff(fd, &link, line));
	return (1);
}
