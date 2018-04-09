/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:38:36 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:14:23 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_block(char const *format, t_printf *block, int i, int j)
{
	int c;

	c = 0;
	block->flags = ft_strsub(format, i + 1, (j - i));
	while (block->flags[c] != 0)
	{
		if (ft_check_char_5(block->flags[c]) == 0)
			return (0);
		c++;
	}
	if (ft_check_order_flags(block) == 0)
		return (0);
	ft_initialize_flags(block);
	if (ft_check_numbers_flags(block) == 0)
		return (0);
	free(block->flags);
	return (1);
}

int		ft_check_numbers_flags(t_printf *block)
{
	if (block->l > 2)
		return (0);
	else if (block->z > 1)
		return (0);
	else if (block->h > 2)
		return (0);
	else if (block->j > 1)
		return (0);
	return (1);
}

void	ft_initialize_flags(t_printf *block)
{
	block->l = 0;
	block->h = 0;
	block->j = 0;
	block->z = 0;
	block->htag = 0;
	block->zero = 0;
	block->plus = 0;
	block->moins = 0;
	block->space = 0;
	block->width = 0;
	block->preci = 0;
	ft_check_flags(block);
}

void	ft_check_flags(t_printf *block)
{
	int i;
	int p;
	int zero;
	int pass;

	pass = 0;
	i = 0;
	p = -1;
	zero = 0;
	while (block->flags[i] != 0)
	{
		if (block->flags[i] == '0' && zero == 0)
			block->zero++;
		else if (block->flags[i] == '.')
			ft_check_flags_3(block, i, &p, &zero);
		else if (ft_check_char_2(block->flags[i]) == 1 && (p == -1 || p == 0))
			ft_check_flags_1(block, i, &zero);
		else if (ft_check_char_2(block->flags[i]) == 1 && (p == 1 || p == 2))
			ft_check_flags_4(block, i, &pass, &zero);
		ft_check_flags_2(block, i);
		i++;
	}
	if (pass == 0)
		block->preci += -1;
	block->point = p;
}

void	ft_check_flags_2(t_printf *block, int i)
{
	if (block->flags[i] == 'z')
		block->z++;
	else if (block->flags[i] == '#')
		block->htag++;
	else if (block->flags[i] == '-')
		block->moins++;
	else if (block->flags[i] == '+')
		block->plus++;
	else if (block->flags[i] == ' ')
		block->space++;
	else if (block->flags[i] == 'l')
		block->l++;
	else if (block->flags[i] == 'h')
		block->h++;
	else if (block->flags[i] == 'j')
		block->j++;
}
