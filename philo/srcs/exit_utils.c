/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:38:37 by *******           #+#    #+#             */
/*   Updated: 2025/05/20 00:43:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

int	ft_exit_busy_wait(t_table *table)
{
	int	end;

	while (1)
	{
		end = ft_table_end_check(table);
		if (end == ERROR)
			return (ERROR);
		else if (end == true)
			return (OK);
		else if (end == false)
			ft_usleep_improved(1000, table);
	}
}

void	ft_exit_destroy_philo_mtx(t_table *table, size_t i)
{
	int	err_code;

	err_code = pthread_mutex_destroy(&table->philo_list[i].n_meal_lock);
	if (err_code)
	{
		ft_error_mtx_destroy(err_code);
		err_code = 0;
	}
	err_code = pthread_mutex_destroy(&table->philo_list[i].last_meal_lock);
	if (err_code)
	{
		ft_error_mtx_destroy(err_code);
		err_code = 0;
	}
	err_code = pthread_mutex_destroy(&table->philo_list[i].finished_lock);
	if (err_code)
	{
		ft_error_mtx_destroy(err_code);
		err_code = 0;
	}
}

void	ft_exit_destroy_table_mtx_print(t_table *table)
{
	int	err_code;

	err_code = pthread_mutex_lock(&table->print_lock);
	if (err_code)
	{
		ft_error_mtx_lock(err_code);
		err_code = 0;
	}
	err_code = pthread_mutex_unlock(&table->print_lock);
	if (err_code)
	{
		ft_error_mtx_unlock(err_code);
		err_code = 0;
	}
	err_code = pthread_mutex_destroy(&table->print_lock);
	if (err_code)
	{
		ft_error_mtx_destroy(err_code);
		err_code = 0;
	}
}

void	ft_exit_destroy_table_mtx_start(t_table *table)
{
	int	err_code;

	err_code = pthread_mutex_lock(&table->start_lock);
	if (err_code)
	{
		ft_error_mtx_lock(err_code);
		err_code = 0;
	}
	err_code = pthread_mutex_unlock(&table->start_lock);
	if (err_code)
	{
		ft_error_mtx_unlock(err_code);
		err_code = 0;
	}
	err_code = pthread_mutex_destroy(&table->start_lock);
	if (err_code)
	{
		ft_error_mtx_destroy(err_code);
		err_code = 0;
	}
}

void	ft_exit_destroy_table_mtx_end(t_table *table)
{
	int	err_code;

	err_code = pthread_mutex_lock(&table->end_lock);
	if (err_code)
	{
		ft_error_mtx_lock(err_code);
		err_code = 0;
	}
	err_code = pthread_mutex_unlock(&table->end_lock);
	if (err_code)
	{
		ft_error_mtx_unlock(err_code);
		err_code = 0;
	}
	err_code = pthread_mutex_destroy(&table->end_lock);
	if (err_code)
	{
		ft_error_mtx_destroy(err_code);
		err_code = 0;
	}
}
