/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:16:42 by MrRobot           #+#    #+#             */
/*   Updated: 2017/01/25 17:52:40 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		main(void)
{
	t_filler	filler;
	char		*line;

	line = NULL;
	ft_initialize_structure(&filler);
	ft_get_player(&filler);
	while (ft_get_next_line(STDIN_FILENO, &line) == 1)
	{
		if (ft_strncmp(line, "Plateau", 7) == 0)
			ft_get_board(&filler.board, ft_strsplit(line, ' '));
		ft_strdel(&line);
		ft_get_next_line(0, &line);
		if (ft_strncmp(line, "Piece", 5) == 0)
			ft_get_piece(&filler.piece, ft_strsplit(line, ' '));
		ft_strdel(&line);
		ft_algo(&filler, filler.board.tab, filler.board.dif);
		if (filler.board.dif != NULL)
			ft_free_tab(filler.board.dif);
		filler.board.dif = ft_tabdup(filler.board.tab);
		ft_printf("%d %d\n", filler.put_y, filler.put_x);
		ft_reset_structure(&filler);
	}
	return (0);
}
