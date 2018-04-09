/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 13:38:19 by MrRobot           #+#    #+#             */
/*   Updated: 2016/02/27 04:20:31 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_initialise_struct(t_flags *flags, int argc)
{
	flags->l = 0;
	flags->r = 0;
	flags->gr = 0;
	flags->a = 0;
	flags->t = 0;
	flags->f = 0;
	flags->file = NULL;
	flags->argc = argc;
	flags->rep = NULL;
	flags->road = 0;
	flags->size.mineur = 0;
	flags->size.majeur = 0;
	flags->size.p = 0;
	flags->p = 0;
	flags->s = 0;
}
