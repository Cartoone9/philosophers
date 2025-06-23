/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqin <jaqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:24:26 by jaqin             #+#    #+#             */
/*   Updated: 2025/04/27 16:11:54 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

void	ft_free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

void	ft_free_strr(char ***strr)
{
	size_t	i;

	if (!(*strr))
		return ;
	i = 0;
	while ((*strr)[i])
	{
		free((*strr)[i]);
		(*strr)[i] = NULL;
		i++;
	}
	if ((*strr))
	{
		free((*strr));
		(*strr) = NULL;
	}
}
