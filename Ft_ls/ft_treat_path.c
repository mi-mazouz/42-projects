/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 16:18:25 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/02 19:48:54 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_treat_path(t_flags *flags, char **argv, int i)
{
	int		j;

	j = i;
	flags->road = 1;
	ft_initialise_cmp(flags);
	ft_check_fake_path(flags, argv, i);
	ft_print_file(flags->file, flags, 0, argv[i]);
	flags->p = 1;
	while (j < flags->argc)
	{
		j++;
		flags->road++;
	}
	if (flags->road < 3)
	{
		flags->rep = malloc(sizeof(t_path));
		ft_strcmp(argv[i], "--") == 0 ? (flags->rep->content = ft_strdup(".")) :
			(flags->rep->content = ft_strdup(argv[i]));
		flags->rep->next = NULL;
		return ;
	}
	ft_treat_path_2(flags);
}

void	ft_treat_path_2(t_flags *flags)
{
	struct stat	rep;

	while (flags->rep != NULL)
	{
		lstat(flags->rep->content, &rep);
		ft_printf("%s:\n", flags->rep->content);
		ft_read_dirr(flags->rep->content, flags);
		flags->rep = flags->rep->next;
	}
	ft_free_lst(&flags->rep);
}
