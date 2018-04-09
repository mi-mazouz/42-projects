/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 08:28:03 by MrRobot           #+#    #+#             */
/*   Updated: 2016/07/10 15:34:25 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_shell				g_shell;

int		main(int argc, char **argv, char **env)
{
	char			*name_term;
	struct termios	term_set;

	argc = 0;
	argv[0] = NULL;
	if ((name_term = getenv("TERM")) == NULL)
		return (ft_error(ER_TERM, NULL));
	tgetent(NULL, name_term);
	if (tcgetattr(0, &g_shell.term_restore) == -1)
		return (0);
	ft_modif_term(&term_set, 0);
	g_shell.env = ft_env_in_list(env);
	ft_init_struct(&g_shell);
	ft_print_prompt(0);
	ft_21sh(&g_shell);
	return (0);
}
