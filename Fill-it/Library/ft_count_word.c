/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:04:45 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/10 11:08:12 by mimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(char const *s, char c)
{
	int	i;
	int	mots;

	mots = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i + 1] == c)
			i++;
		if (s[i] == c)
			i++;
		while (s[i] != c && s[i] != 0)
			i++;
		if (s[i] == 0 && s[i - 1] != c)
			mots++;
		if (s[i] == 0)
			mots--;
		mots++;
	}
	return (mots);
}
