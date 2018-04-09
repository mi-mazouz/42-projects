/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 17:53:06 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/04 08:53:11 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char **argv)
{
	char		*name_term;
	t_select	sel;

	if (argc < 2)
		return (ft_error(1));
	if ((name_term = getenv("TERM")) == NULL)
		return (ft_error(2));
	if (!(tgetent(NULL, name_term)))
		return (0);
	if (tcgetattr(0, &sel.term_update) == -1)
		return (0);
	if (tcgetattr(0, &sel.term_restore) == -1)
		return (0);
	ioctl(STDIN_FILENO, TIOCGWINSZ, &sel.win);
	ft_make_list(&sel, argv);
	ft_init_struct(&sel);
	ft_modif_term(&sel);
	ft_read_key(&sel);
	return (0);
}
