/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:26:27 by *******           #+#    #+#             */
/*   Updated: 2025/05/12 21:56:00 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static void	*ft_philo_routine(void *source);
static bool	ft_philo_full_check(t_philo *philo);

int	ft_create_threads(t_table *table)
{
	int		i;
	int		err_code;
	t_philo	*cursor_p;

	i = 0;
	err_code = pthread_mutex_lock(&table->start_lock);
	if (err_code)
		return (ft_error_mtx_lock(err_code));
	while (i < (int)table->n_philo)
	{
		cursor_p = &table->philo_list[i];
		err_code = pthread_create(&cursor_p->thread_id, NULL,
				ft_philo_routine, cursor_p);
		if (err_code)
			return (ft_error_thread_crt(err_code));
		i++;
	}
	table->start_time = ft_gettime_ms();
	if (table->start_time == ERROR)
		return (ERROR);
	table->threads_rdy = true;
	err_code = pthread_mutex_unlock(&table->start_lock);
	if (err_code)
		return (ft_error_mtx_unlock(err_code));
	return (OK);
}

static void	*ft_philo_routine(void *source)
{
	t_philo	*philo;

	philo = (t_philo *)source;
	if (ft_wait_all_threads(philo->table) == ERROR)
		return (NULL);
	if (philo->philo_id % 2 == 0)
	{
		if (ft_usleep_improved(1000, philo->table) == ERROR)
			return (NULL);
	}
	while (!ft_philo_full_check(philo) && !ft_philo_end_check(philo))
	{
		ft_eat(philo);
		if (ft_philo_full_check(philo) || ft_philo_end_check(philo))
			return (source);
		ft_sleep(philo);
		if (ft_philo_full_check(philo) || ft_philo_end_check(philo))
			return (source);
		ft_think(philo);
	}
	return (source);
}

int	ft_wait_all_threads(t_table *table)
{
	bool	ready;
	int		err_code;

	while (1)
	{
		err_code = pthread_mutex_lock(&table->start_lock);
		if (err_code)
			return (ft_error_mtx_lock(err_code));
		ready = table->threads_rdy;
		err_code = pthread_mutex_unlock(&table->start_lock);
		if (err_code)
			return (ft_error_mtx_unlock(err_code));
		if (ready)
			break ;
		else
			ft_usleep_improved(10, table);
	}
	return (OK);
}

bool	ft_philo_end_check(t_philo *philo)
{
	int		err_code;
	bool	ret;

	err_code = pthread_mutex_lock(&philo->table->end_lock);
	if (err_code)
	{
		ft_error_mtx_lock(err_code);
		return (true);
	}
	ret = philo->table->end;
	err_code = pthread_mutex_unlock(&philo->table->end_lock);
	if (err_code)
	{
		ft_error_mtx_unlock(err_code);
		return (true);
	}
	return (ret);
}

static bool	ft_philo_full_check(t_philo *philo)
{
	int		err_code;
	bool	ret;

	err_code = pthread_mutex_lock(&philo->finished_lock);
	if (err_code)
	{
		ft_error_mtx_lock(err_code);
		return (true);
	}
	ret = philo->finished;
	err_code = pthread_mutex_unlock(&philo->finished_lock);
	if (err_code)
	{
		ft_error_mtx_unlock(err_code);
		return (true);
	}
	return (ret);
}
