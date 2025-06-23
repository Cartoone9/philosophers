/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_spoon_n_philo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:26:27 by *******           #+#    #+#             */
/*   Updated: 2025/05/11 20:18:59 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static int	ft_assign_spoon(t_philo *philo, t_table *table);
static int	ft_init_philo_mutex(t_philo *cursor_p);

int	ft_make_spoon(t_table *table)
{
	int		index;
	int		err_code;

	if (!table)
		return (ERROR);
	table->spoon_list = malloc(sizeof(t_spoon) * table->n_philo);
	if (!table->spoon_list)
		return (ERROR);
	index = 0;
	err_code = 0;
	while (index < (int)table->n_philo)
	{
		err_code = pthread_mutex_init(&table->spoon_list[index].lock, NULL);
		if (err_code)
			return (ft_error_mtx_init(err_code));
		index++;
	}
	return (OK);
}

int	ft_make_philo(t_table *table)
{
	int		index;
	t_philo	*cursor_p;

	if (!table)
		return (ERROR);
	table->philo_list = malloc(sizeof(t_philo) * table->n_philo);
	if (!table->philo_list)
		return (ERROR);
	index = 0;
	while (index < (int)table->n_philo)
	{
		cursor_p = &table->philo_list[index];
		cursor_p->thread_id = -1;
		cursor_p->philo_id = index + 1;
		cursor_p->n_meal = 0;
		cursor_p->t_last_meal = 0;
		cursor_p->finished = false;
		cursor_p->table = table;
		if (ft_assign_spoon(cursor_p, table) == ERROR)
			return (ERROR);
		if (ft_init_philo_mutex(cursor_p) == ERROR)
			return (ERROR);
		index++;
	}
	return (OK);
}

static int	ft_assign_spoon(t_philo *philo, t_table *table)
{
	if (!philo || !table)
		return (ERROR);
	philo->right_spoon = &table->spoon_list[philo->philo_id - 1];
	if (philo->philo_id == table->n_philo)
	{
		philo->left_spoon = &table->spoon_list[0];
	}
	else
	{
		philo->left_spoon = &table->spoon_list[philo->philo_id];
	}
	return (OK);
}

static int	ft_init_philo_mutex(t_philo *cursor_p)
{
	int	err_code;

	err_code = pthread_mutex_init(&cursor_p->n_meal_lock, NULL);
	if (err_code)
		return (ft_error_mtx_init(err_code));
	err_code = pthread_mutex_init(&cursor_p->last_meal_lock, NULL);
	if (err_code)
		return (ft_error_mtx_init(err_code));
	err_code = pthread_mutex_init(&cursor_p->finished_lock, NULL);
	if (err_code)
		return (ft_error_mtx_init(err_code));
	return (OK);
}
