/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_block.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:28:58 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/31 16:22:40 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_t_block(t_printf *link, va_list ap)
{
	ft_initialize_flags(link);
	if (ft_check_letter(link, ap) == 0)
		return (0);
	free(link->flags);
	return (1);
}

int	ft_check_letter(t_printf *link, va_list ap)
{
	int p;

	p = 0;
	if (link->letter == 'c' && ft_result_letter_c(link, ap) == 1)
		return (1);
	else if (link->letter == 'C' && ft_result_letter_tall_c(link, ap) == 1)
		return (1);
	else if ((link->letter == 's' || link->letter == 'S') &&
			ft_result_letter_s(link, ap) == 1)
		return (1);
	else if ((link->letter == 'd' || link->letter == 'i' || link->letter == 'D')
			&& ft_result_letter_d(link, ap) == 1)
		return (1);
	else if ((link->letter == 'u' || link->letter == 'U') &&
			ft_result_letter_u(link, ap) == 1)
		return (1);
	else if ((link->letter == 'o' || link->letter == 'O') &&
			ft_result_letter_o(link, ap) == 1)
		return (1);
	else if (ft_check_letter_2(link, ap) == 1)
		return (1);
	return (0);
}

int	ft_check_letter_2(t_printf *link, va_list ap)
{
	if (link->letter == 'p' && ft_result_letter_p(link, ap) == 1)
		return (1);
	else if ((link->letter == 'x' || link->letter == 'X') &&
			ft_result_letter_x(link, ap) == 1)
		return (1);
	else if (link->letter == 'b' && ft_result_letter_b(link, ap) == 1)
		return (1);
	else if (link->letter == '%' && ft_result_letter_percent(link) == 1)
		return (1);
	return (0);
}
