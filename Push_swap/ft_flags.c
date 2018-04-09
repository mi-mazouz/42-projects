/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 09:06:48 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/10 19:53:15 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_flags(char *argv, t_stc *stc)
{
	int i;

	i = 0;
	while (argv[i] != 0)
	{
		if (argv[i] == '-' && i == 0)
			i += 0;
		else if (argv[i] == 'c')
			stc->c = 1;
		else if (argv[i] == 'r')
			stc->r = 1;
		else if (argv[i] == 'n')
			stc->n = 1;
		else if (argv[i] == 'a')
			stc->a = 1;
		else if (argv[i] == 'b')
			stc->b = 1;
		else if (argv[i] == 'p')
			stc->p = 1;
		else
			return (0);
		i++;
	}
	return (1);
}
