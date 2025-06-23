/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:38:37 by *******           #+#    #+#             */
/*   Updated: 2025/05/20 00:39:57 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static void	ft_exit_handle_philo(t_table *table);

void	ft_clean_table(t_table *table)
{
	int	err_code;
	int	i;

	if (!table || ft_exit_busy_wait(table) == ERROR)
		return ;
	if (table->philo_list)
		ft_exit_handle_philo(table);
	if (table->spoon_list)
	{
		i = -1;
		while (++i < (int)table->n_philo)
		{
			err_code = pthread_mutex_destroy(&table->spoon_list[i].lock);
			if (err_code)
			{
				ft_error_mtx_destroy(err_code);
				err_code = 0;
			}
		}
		free(table->spoon_list);
		table->spoon_list = NULL;
	}
	ft_exit_destroy_table_mtx_print(table);
	ft_exit_destroy_table_mtx_start(table);
	ft_exit_destroy_table_mtx_end(table);
}

static void	ft_exit_handle_philo(t_table *table)
{
	int	i;

	i = -1;
	while (++i < (int)table->n_philo)
		ft_exit_destroy_philo_mtx(table, i);
	free(table->philo_list);
	table->philo_list = NULL;
}
