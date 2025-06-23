/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_meal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:26:27 by *******           #+#    #+#             */
/*   Updated: 2025/05/11 21:03:33 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static int	ft_iterate_all_philos_meal_check(t_table *table);
static int	ft_check_one_philo_meals(t_table *table, t_philo *philo);
static int	ft_mark_philo_finished(t_philo *philo);

int	ft_monitor_max_meal(t_table *table)
{
	int	iteration_result;
	int	finalize_result;

	if (table->max_meal == -1)
		return (false);
	iteration_result = ft_iterate_all_philos_meal_check(table);
	if (iteration_result == 1)
		return (false);
	if (iteration_result != 0)
		return (iteration_result);
	finalize_result = ft_set_simulation_end(table);
	if (finalize_result != 0)
		return (finalize_result);
	return (true);
}

static int	ft_iterate_all_philos_meal_check(t_table *table)
{
	int	i;
	int	philo_check_status;

	i = 0;
	while (i < table->n_philo)
	{
		philo_check_status = ft_check_one_philo_meals(table,
				&table->philo_list[i]);
		if (philo_check_status == 1)
			return (true);
		if (philo_check_status != 0)
			return (philo_check_status);
		i++;
	}
	return (false);
}

static int	ft_check_one_philo_meals(t_table *table, t_philo *philo)
{
	int	err_code;
	int	n_meal_val;

	err_code = pthread_mutex_lock(&philo->n_meal_lock);
	if (err_code)
		return (ft_error_mtx_lock(err_code));
	n_meal_val = philo->n_meal;
	err_code = pthread_mutex_unlock(&philo->n_meal_lock);
	if (err_code)
		return (ft_error_mtx_unlock(err_code));
	if (n_meal_val < table->max_meal)
		return (true);
	else
	{
		err_code = ft_mark_philo_finished(philo);
		if (err_code)
			return (err_code);
	}
	return (false);
}

static int	ft_mark_philo_finished(t_philo *philo)
{
	int	err_code;

	err_code = pthread_mutex_lock(&philo->finished_lock);
	if (err_code)
		return (ft_error_mtx_lock(err_code));
	philo->finished = true;
	err_code = pthread_mutex_unlock(&philo->finished_lock);
	if (err_code)
		return (ft_error_mtx_unlock(err_code));
	return (OK);
}

int	ft_set_simulation_end(t_table *table)
{
	int	err_code;

	err_code = pthread_mutex_lock(&table->end_lock);
	if (err_code)
		return (ft_error_mtx_lock(err_code));
	table->end = true;
	err_code = pthread_mutex_unlock(&table->end_lock);
	if (err_code)
		return (ft_error_mtx_unlock(err_code));
	return (OK);
}
