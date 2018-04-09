/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:45:26 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/03 19:50:33 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	unsigned char	c2;

	c2 = (unsigned char)c;
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	i = 0;
	while (n > 0)
	{
		ptr_dst[i] = ptr_src[i];
		if (ptr_src[i] == c2)
			return (ptr_dst + i + 1);
		n--;
		i++;
	}
	return (NULL);
}
