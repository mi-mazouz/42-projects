/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:46:04 by mimazouz          #+#    #+#             */
/*   Updated: 2015/11/30 17:15:30 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*ptr_src;
	unsigned char	ptr_c;
	void			*ret;

	ptr_c = (unsigned char)c;
	ptr_src = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		if (ptr_src[i] == ptr_c)
		{
			ret = (void *)ptr_src;
			return (ret + i);
		}
		i++;
		n--;
	}
	return (NULL);
}
