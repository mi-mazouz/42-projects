/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:07:30 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/09 18:37:54 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s1;

	i = 0;
	if (!s || !f)
		return (NULL);
	s1 = ft_strnew(ft_strlen(s));
	if (!s1)
		return (NULL);
	while (s[i])
	{
		s1[i] = (*f)(i, s[i]);
		i++;
	}
	return (s1);
}
