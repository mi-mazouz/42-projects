/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:05:35 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/10 10:25:25 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	int		i;
	char	*s;

	s = (char *)malloc(sizeof(*s) * (size + 1));
	i = 0;
	if (!s)
		return (NULL);
	ft_bzero((void *)s, size + 1);
	return (s);
}
