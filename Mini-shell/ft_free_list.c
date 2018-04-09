/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:33:58 by MrRobot           #+#    #+#             */
/*   Updated: 2016/03/24 22:01:12 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_list(t_env **env)
{
	t_env	*ptr;

	ptr = *env;
	while (ptr != NULL)
	{
		*env = (*env)->next;
		free(ptr->var);
		free(ptr->value);
		free(ptr);
		ptr = *env;
	}
}
