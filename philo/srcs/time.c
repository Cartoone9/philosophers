/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:08:47 by *******           #+#    #+#             */
/*   Updated: 2025/05/20 00:04:29 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

long long	ft_gettime_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		ft_error_min("gettimeofday failed");
		return (ERROR);
	}
	return (((long long)tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));
}

long long	ft_gettime_us(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		ft_error_min("gettimeofday failed");
		return (ERROR);
	}
	return (((long long)tv.tv_sec * 1000000LL) + tv.tv_usec);
}
