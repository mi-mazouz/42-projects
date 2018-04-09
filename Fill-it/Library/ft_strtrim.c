/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:08:47 by mimazouz          #+#    #+#             */
/*   Updated: 2015/11/30 18:48:20 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	d;
	size_t	t;
	char	*s1;

	i = 0;
	if (!s)
		return (NULL);
	t = ft_strlen(s) - 1;
	while (i <= t && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (t >= i && (s[t] == ' ' || s[t] == '\n' || s[t] == '\t'))
		t--;
	d = t - i + 1;
	s1 = ft_strsub(s, i, d);
	return (s1);
}
