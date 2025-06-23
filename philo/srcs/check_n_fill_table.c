/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_fill_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:26:27 by *******           #+#    #+#             */
/*   Updated: 2025/05/09 20:09:48 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static inline void	ft_init_table_data(t_table *table);
static int		ft_init_table_mutex(t_table *table);

int	ft_check_n_fill_table(char **av, t_table *table)
{
	int		ret;
	size_t	i;

	if (!av || !table || ft_init_table_mutex(table) == ERROR)
		return (ERROR);
	ft_init_table_data(table);
	ret = 0;
	i = 1;
	while (av[i])
	{
		if (i == 1)
			ret = ft_fill_n_philo(av[i], table);
		else if (i == 2)
			ret = ft_fill_t_die(av[i], table);
		else if (i == 3)
			ret = ft_fill_t_eat(av[i], table);
		else if (i == 4)
			ret = ft_fill_t_sleep(av[i], table);
		else if (i == 5)
			ret = ft_fill_max_meal(av[i], table);
		if (ret == ERROR)
			return (ERROR);
		i++;
	}
	return (OK);
}

static int	ft_init_table_mutex(t_table *table)
{
	int	err_code;

	err_code = pthread_mutex_init(&table->start_lock, NULL);
	if (err_code)
		return (ft_error_mtx_init(err_code));
	err_code = pthread_mutex_init(&table->print_lock, NULL);
	if (err_code)
		return (ft_error_mtx_init(err_code));
	err_code = pthread_mutex_init(&table->end_lock, NULL);
	if (err_code)
		return (ft_error_mtx_init(err_code));
	return (OK);
}

static inline void	ft_init_table_data(t_table *table)
{
	table->n_philo = 0;
	table->t_die = 0;
	table->t_eat = 0;
	table->t_sleep = 0;
	table->max_meal = -1;
	table->start_time = -1;
	table->end = false;
	table->threads_rdy = false;
	table->philo_list = NULL;
	table->spoon_list = NULL;
}
