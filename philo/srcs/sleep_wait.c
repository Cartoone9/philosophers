/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_wait.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:08:47 by *******           #+#    #+#             */
/*   Updated: 2025/05/20 00:24:25 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

int	ft_busy_wait(long long wait_time, long long t_start_us,
				t_table *table)
{
	long long	t_current_us;
	int			ended;

	while (1)
	{
		ended = ft_table_end_check(table);
		if (ended == ERROR)
			return (ERROR);
		if (ended == true)
			return (true);
		t_current_us = ft_gettime_us();
		if (t_current_us == ERROR)
			return (ERROR);
		if (t_current_us - t_start_us < wait_time)
			usleep(10);
		else
			break ;
	}
	return (OK);
}
