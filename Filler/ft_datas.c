/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:35:32 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/24 19:33:24 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void		ft_get_piece(t_piece *piece, char **split)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	piece->y = ft_atoi(split[1]);
	piece->x = ft_atoi(split[2]);
	ft_free_tab(split);
	while (i < piece->y)
	{
		ft_get_next_line(0, &line);
		if (piece->tab == NULL)
			piece->tab = ft_tab_add_first(NULL, line);
		else
		{
			split = piece->tab;
			piece->tab = ft_tab_add_last(split, line);
			ft_free_tab(split);
		}
		ft_strdel(&line);
		i++;
	}
}

void		ft_get_board(t_board *board, char **split)
{
	char	*line;
	int		i;

	line = NULL;
	i = -1;
	board->y = ft_atoi(split[1]);
	board->x = ft_atoi(split[2]);
	ft_free_tab(split);
	ft_get_next_line(0, &line);
	ft_strdel(&line);
	while (++i < board->y)
	{
		ft_get_next_line(0, &line);
		if (board->tab == NULL)
			board->tab = ft_tab_add_first(NULL, ft_strsub(line, 4,
						ft_strlen(line) - 4));
		else
		{
			split = board->tab;
			board->tab = ft_tab_add_last(split, ft_strsub(line, 4,
						ft_strlen(line) - 4));
			ft_free_tab(split);
		}
		ft_strdel(&line);
	}
}

void		ft_get_player(t_filler *filler)
{
	char	*line;

	line = NULL;
	ft_get_next_line(0, &line);
	if (ft_strncmp(line, "$$$ exec p1", 11) == 0)
	{
		filler->players.me = 'O';
		filler->players.enemy = 'X';
	}
	else if (ft_strncmp(line, "$$$ exec p2", 11) == 0)
	{
		filler->players.me = 'X';
		filler->players.enemy = 'O';
	}
	ft_strdel(&line);
}
