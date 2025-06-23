/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:26:27 by *******           #+#    #+#             */
/*   Updated: 2025/05/12 22:24:24 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static void	*ft_monitor_routine(void *source);
static int	ft_monitor_death(t_table *table);
static int	ft_took_too_long(t_philo *philo);

int	ft_create_monitor(t_table *table)
{
	int			err_code;
	pthread_t	monitor;

	err_code = pthread_create(&monitor, NULL, ft_monitor_routine, table);
	if (err_code)
		return (ft_error_thread_crt(err_code));
	err_code = pthread_detach(monitor);
	if (err_code)
		return (ft_error_thread_dtch(err_code));
	return (OK);
}

static void	*ft_monitor_routine(void *source)
{
	t_table	*table;
	int		ret;

	table = (t_table *)source;
	if (ft_wait_all_threads(table) == ERROR)
		return (NULL);
	while (1)
	{
		ret = ft_monitor_death(table);
		if (ret == ERROR)
			return (NULL);
		else if (ret)
			break ;
		ret = ft_monitor_max_meal(table);
		if (ret == ERROR)
			return (NULL);
		else if (ret)
			break ;
		ft_usleep_improved(10, table);
	}
	return (source);
}

static int	ft_monitor_death(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		if (ft_took_too_long(&table->philo_list[i]))
		{
			if (ft_set_simulation_end(table) == ERROR)
				return (ERROR);
			if (ft_print_status(&table->philo_list[i],
					RED "died" RESET) == ERROR)
				return (true);
			return (true);
		}
		i++;
	}
	return (false);
}

static int	ft_took_too_long(t_philo *philo)
{
	long long	current_time_ms;
	long long	meal_ref_time_ms;
	long long	time_to_die_ms;
	int			err_code;

	if (!philo || philo->table->start_time == -1)
		return (false);
	current_time_ms = ft_gettime_ms();
	if (current_time_ms == ERROR)
		return (true);
	time_to_die_ms = philo->table->t_die / 1000;
	err_code = pthread_mutex_lock(&philo->last_meal_lock);
	if (err_code)
		return (ft_error_mtx_lock(err_code), true);
	if (philo->t_last_meal == 0)
		meal_ref_time_ms = philo->table->start_time;
	else
		meal_ref_time_ms = philo->t_last_meal;
	err_code = pthread_mutex_unlock(&philo->last_meal_lock);
	if (err_code)
		return (ft_error_mtx_unlock(err_code), true);
	if (current_time_ms - meal_ref_time_ms >= time_to_die_ms)
		return (true);
	return (false);
}
