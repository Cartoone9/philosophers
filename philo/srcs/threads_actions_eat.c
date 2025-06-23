/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_actions_eat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:26:27 by *******           #+#    #+#             */
/*   Updated: 2025/05/15 16:34:36 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static int	ft_update_philo_meal_stats(t_philo *philo);
static int	ft_release_spoons_after_eating(t_philo *philo);

int	ft_try_acquire_left_spoon(t_philo *philo, bool even)
{
	int	err_code;

	err_code = pthread_mutex_lock(&philo->left_spoon->lock);
	if (err_code)
		return (ft_error_mtx_lock(err_code));
	if (ft_philo_end_check(philo))
	{
		err_code = pthread_mutex_unlock(&philo->left_spoon->lock);
		if (err_code)
			return (ft_error_mtx_unlock(err_code));
		if (even == false)
		{
			err_code = pthread_mutex_unlock(&philo->right_spoon->lock);
			if (err_code)
				return (ft_error_mtx_unlock(err_code));
		}
		return (1);
	}
	ft_print_status(philo, ORANGE "has taken a fork" RESET);
	return (OK);
}

int	ft_try_acquire_right_spoon(t_philo *philo, bool even)
{
	int	err_code;

	err_code = pthread_mutex_lock(&philo->right_spoon->lock);
	if (err_code)
		return (ft_error_mtx_lock(err_code));
	if (ft_philo_end_check(philo))
	{
		err_code = pthread_mutex_unlock(&philo->right_spoon->lock);
		if (err_code)
			return (ft_error_mtx_unlock(err_code));
		if (even == true)
		{
			err_code = pthread_mutex_unlock(&philo->left_spoon->lock);
			if (err_code)
				return (ft_error_mtx_unlock(err_code));
		}
		return (1);
	}
	ft_print_status(philo, ORANGE "has taken a fork" RESET);
	return (OK);
}

int	ft_actions_while_holding_spoons(t_philo *philo)
{
	if (ft_update_philo_meal_stats(philo) == ERROR)
		return (ERROR);
	ft_print_status(philo, YELLOW "is eating" RESET);
	if (ft_usleep_improved(philo->table->t_eat, philo->table) == ERROR)
		return (ERROR);
	return (ft_release_spoons_after_eating(philo));
}

static int	ft_update_philo_meal_stats(t_philo *philo)
{
	int	err_code;

	err_code = pthread_mutex_lock(&philo->last_meal_lock);
	if (err_code)
		return (ft_error_mtx_lock(err_code));
	philo->t_last_meal = ft_gettime_ms();
	err_code = pthread_mutex_unlock(&philo->last_meal_lock);
	if (err_code)
		return (ft_error_mtx_unlock(err_code));
	if (philo->t_last_meal == ERROR)
		return (ERROR);
	err_code = pthread_mutex_lock(&philo->n_meal_lock);
	if (err_code)
		return (ft_error_mtx_lock(err_code));
	philo->n_meal++;
	err_code = pthread_mutex_unlock(&philo->n_meal_lock);
	if (err_code)
		return (ft_error_mtx_unlock(err_code));
	return (OK);
}

static int	ft_release_spoons_after_eating(t_philo *philo)
{
	int	err_code;

	err_code = pthread_mutex_unlock(&philo->left_spoon->lock);
	if (err_code)
		return (ft_error_mtx_unlock(err_code));
	err_code = pthread_mutex_unlock(&philo->right_spoon->lock);
	if (err_code)
		return (ft_error_mtx_unlock(err_code));
	return (OK);
}
