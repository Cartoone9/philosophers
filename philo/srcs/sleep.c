/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:08:47 by *******           #+#    #+#             */
/*   Updated: 2025/05/20 00:16:37 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static int	ft_usleep_main_loop(long long wait_time, t_table *table,
				long long t_start_us);
static int	ft_pre_wait_checks(t_table *table, long long t_start_us,
				long long wait_time, long long *t_elapsed);
static int	ft_execute_wait(long long time_remaining, t_table *table,
				long long original_wait_time, long long t_start_us);
static int	ft_usleep_chk(long long total_time, t_table *table);

int	ft_usleep_improved(long long wait_time, t_table *table)
{
	long long	t_start_us;

	if (wait_time <= 0 || !table)
		return (ERROR);
	t_start_us = ft_gettime_us();
	if (t_start_us == ERROR)
		return (ERROR);
	return (ft_usleep_main_loop(wait_time, table, t_start_us));
}

static int	ft_usleep_main_loop(long long wait_time, t_table *table,
				long long t_start_us)
{
	int			status;
	long long	t_elapsed;

	while (1)
	{
		status = ft_pre_wait_checks(table, t_start_us, wait_time,
				&t_elapsed);
		if (status == ERROR)
			return (ERROR);
		if (status == OK)
			return (OK);
		status = ft_execute_wait(wait_time - t_elapsed, table,
				wait_time, t_start_us);
		if (status == ERROR)
			return (ERROR);
		if (status == true)
			return (OK);
	}
}

static int	ft_pre_wait_checks(t_table *table, long long t_start_us,
				long long wait_time, long long *t_elapsed)
{
	int			ended_status;
	long long	t_current_us;

	ended_status = ft_table_end_check(table);
	if (ended_status == ERROR)
		return (ERROR);
	if (ended_status == true)
		return (OK);
	t_current_us = ft_gettime_us();
	if (t_current_us == ERROR)
		return (ERROR);
	*t_elapsed = t_current_us - t_start_us;
	if (*t_elapsed >= wait_time)
		return (OK);
	return (1);
}

static int	ft_execute_wait(long long time_remaining, t_table *table,
				long long original_wait_time, long long t_start_us)
{
	if (time_remaining > 1000)
	{
		return (ft_usleep_chk(time_remaining / 2, table));
	}
	else
	{
		return (ft_busy_wait(original_wait_time, t_start_us, table));
	}
}

static int	ft_usleep_chk(long long total_time, t_table *table)
{
	long long	elapsed_time;
	int			ended;

	elapsed_time = 0;
	while (elapsed_time < total_time)
	{
		ended = ft_table_end_check(table);
		if (ended == ERROR)
			return (ERROR);
		if (ended == true)
			return (true);
		usleep(1000);
		elapsed_time += 1000;
	}
	return (OK);
}
