/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:47:33 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/04 18:44:26 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int compt;

	compt = 0;
	while (src[compt] != '\0')
	{
		dst[compt] = src[compt];
		compt++;
	}
	dst[compt] = '\0';
	return (dst);
}
