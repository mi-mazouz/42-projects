/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:34:52 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/13 18:17:40 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_argv(int argc, char **argv, t_stc *stc)
{
	int		i;
	long	value;

	i = 1;
	while (i < argc)
	{
		if (stc->pa == NULL && argv[i][1] >= 'a' && argv[i][1] <= 'z')
		{
			if (ft_flags(argv[i], stc) == 0)
				return (0);
			i++;
			continue ;
		}
		if (ft_str_size(argv[i]) == 0)
			return (0);
		value = ft_atoi_l(argv[i]);
		if (value > 2147483647 || value < -2147483648)
			return (0);
		else
			ft_make_list(&stc->pa, argv[i]);
		i++;
	}
	if (stc->pa && ft_check_double(stc) == 0)
		return (0);
	return (1);
}
