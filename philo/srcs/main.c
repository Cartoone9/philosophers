/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:26:27 by *******           #+#    #+#             */
/*   Updated: 2025/05/09 20:06:38 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static bool	ft_main_end_check(t_table *table);
static int	ft_join_threads(t_table *table);
static int	ft_single_philo(t_table *table);

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		if (ft_check_n_fill_table(av, &table) == ERROR)
			return (ERROR);
		if (ft_make_spoon(&table) == ERROR || ft_make_philo(&table) == ERROR)
		{
			ft_clean_table(&table);
			return (ERROR);
		}
		if (table.max_meal == 0)
			return (OK);
		ft_print_banner();
		ft_start_diner(&table);
		ft_clean_table(&table);
	}
	else
	{
		ft_error_arg();
		return (ERROR);
	}
	return (OK);
}

int	ft_start_diner(t_table *table)
{
	if (table->n_philo == 0 || table->max_meal == 0)
		return (OK);
	else if (table->n_philo == 1)
	{
		ft_single_philo(table);
		return (OK);
	}
	else
	{
		if (ft_create_monitor(table) == ERROR
			|| ft_create_threads(table) == ERROR)
			return (ERROR);
	}
	while (!ft_main_end_check(table))
		ft_usleep_improved(1000, table);
	if (ft_join_threads(table) == ERROR)
		return (ERROR);
	return (OK);
}

static int	ft_single_philo(t_table *table)
{
	long long	time;

	time = 0;
	printf(BOLD""GREY"[%llu] "RESET"philo nº%i %s\n",
		time, 1, ORANGE"has taken a fork"RESET);
	if (ft_usleep_improved(table->t_die, table) == ERROR)
		return (ERROR);
	time = table->t_die / 1000;
	printf(BOLD""GREY"[%llu] "RESET"philo nº%i %s\n", time, 1, RED"died"RESET);
	table->end = true;
	return (OK);
}

static bool	ft_main_end_check(t_table *table)
{
	int		err_code;
	bool	ret;

	err_code = pthread_mutex_lock(&table->end_lock);
	if (err_code)
	{
		ft_error_mtx_lock(err_code);
		return (true);
	}
	ret = table->end;
	err_code = pthread_mutex_unlock(&table->end_lock);
	if (err_code)
	{
		ft_error_mtx_unlock(err_code);
		return (true);
	}
	return (ret);
}

static int	ft_join_threads(t_table *table)
{
	int	err_code;
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		err_code = pthread_join(table->philo_list[i].thread_id, NULL);
		if (err_code)
			return (ft_error_thread_join(err_code));
		i++;
	}
	return (OK);
}
