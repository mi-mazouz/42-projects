/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:08:21 by mimazouz          #+#    #+#             */
/*   Updated: 2016/07/22 15:54:41 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	while (s1[i] != 0)
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
		s3[i++] = s2[j++];
	s3[i] = 0;
	return (s3);
}
