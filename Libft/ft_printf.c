/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:12:01 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/20 17:17:31 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_treat_block_2(t_printf *block, int test)
{
	if (test == 0)
	{
		g_octet = g_octet + ft_return_octet(block->frmt[block->i]);
		ft_conv_wchar(block->frmt[block->i]);
		block->i++;
	}
	else
	{
		ft_putchar('%');
		block->i += 2;
		g_octet = g_octet + ft_return_octet(block->frmt[block->i]);
	}
}

int		ft_check_all_block(char const *format, int i, int j, t_printf block)
{
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			i += 2;
			continue ;
		}
		else if (format[i] == '%' && format[i + 1] != 0)
		{
			j = i + 1;
			while (format[j] != 0 && ft_check_char_4(format[j]) != 1)
				j++;
			if (ft_check_char_4(format[j]) == 1)
				if (ft_check_block(format, &block, i, j) == 0)
					return (0);
			if (format[j] == 0)
				return (0);
			i = j + 1;
		}
		else if (format[i] == '%')
			return (0);
		else
			i++;
	}
	return (1);
}

int		ft_treat_block(t_printf block, int j, va_list ap)
{
	while (block.frmt[block.i] != '\0')
	{
		if (block.frmt[block.i] == '%' && block.frmt[block.i + 1] == '%')
		{
			ft_treat_block_2(&block, 1);
			continue ;
		}
		else if (block.frmt[block.i] == '%')
		{
			j = block.i + 1;
			while (block.frmt[j] != 0 && ft_check_char_4(block.frmt[j]) != 1)
				j++;
			if (ft_check_char_4(block.frmt[j]) == 1)
			{
				block.flags = ft_strsub(block.frmt, block.i + 1, (j - block.i));
				block.letter = block.frmt[j];
				if ((ft_t_block(&block, ap)) == 0)
					return (0);
			}
			block.i = j + 1;
		}
		else
			ft_treat_block_2(&block, 0);
	}
	return (1);
}

int		ft_printf(char const *format, ...)
{
	va_list		ap;
	t_printf	block;

	g_octet = 0;
	va_start(ap, format);
	block.frmt = ft_strdup(format);
	block.i = 0;
	if ((ft_check_all_block(format, 0, 0, block)) == 0)
		return (0);
	if (ft_treat_block(block, 0, ap) == 0)
		return (0);
	free(block.frmt);
	va_end(ap);
	return (g_octet);
}
