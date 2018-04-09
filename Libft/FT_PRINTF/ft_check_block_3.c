/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_block_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:21:31 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:14:45 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_flags_1(t_printf *block, int i, int *zero)
{
	block->width = block->width * 10 + (block->flags[i] - 48);
	*zero = 1;
}

void	ft_check_flags_4(t_printf *block, int i, int *pass, int *zero)
{
	block->preci = block->preci * 10 + (block->flags[i] - 48);
	*zero = 1;
	*pass = 1;
}

void	ft_check_flags_3(t_printf *block, int i, int *p, int *zero)
{
	(*p)++;
	if (block->flags[i - 1] >= '0' && block->flags[i - 1] <= '9')
		(*p)++;
	if (block->flags[i + 1] >= '0' && block->flags[i + 1] <= '9')
	{
		*p = 2;
		*zero = 1;
	}
}
