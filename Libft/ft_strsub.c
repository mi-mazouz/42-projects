/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:08:00 by mimazouz          #+#    #+#             */
/*   Updated: 2016/03/26 19:44:56 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*s1;

	i = 0;
	if (!(s1 = ft_strnew(len)))
		return (NULL);
	while (len != 0)
	{
		s1[i] = s[start];
		start++;
		i++;
		len--;
	}
	return (s1);
}
