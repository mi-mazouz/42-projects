/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 18:06:26 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/13 18:26:11 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stc		stc;
	t_stack		*curs_a;
	t_stack		*curs_b;

	ft_init_stc(&stc, &curs_a, &curs_b);
	if (ft_check_argv(argc, argv, &stc) == 0)
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	if (argc < 2 || stc.pa == NULL)
		return (-1);
	if (ft_check_sort(stc.pa) == 0)
		ft_algo_sort(&stc, curs_a, curs_b);
	if (stc.r == 1)
		ft_print_result(stc);
	if (stc.n == 1)
		ft_printf("Nombre d'operation: %ld\n", stc.nb_op);
	ft_free_list(&stc.pa);
	return (0);
}
