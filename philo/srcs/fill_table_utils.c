/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_table_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:26:27 by *******           #+#    #+#             */
/*   Updated: 2025/05/11 21:03:21 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

int	ft_fill_n_philo(char *source, t_table *table)
{
	if (ft_has_only_pdigit(source) == false
		|| ft_strlen(source) > 10
		|| ft_atoll_safe(source, &table->n_philo) == ERROR
		|| table->n_philo > 200 || table->n_philo < 1)
	{
		ft_error_source(source, "': Invalid argument for nb_philosophers");
		return (ERROR);
	}
	return (OK);
}

// we multiply by 1000
// to go from miliseconds to microseconds
int	ft_fill_t_die(char *source, t_table *table)
{
	if (ft_has_only_pdigit(source) == false
		|| ft_strlen(source) > 10
		|| ft_atoll_safe(source, &table->t_die) == ERROR
		|| table->t_die > INT_MAX || table->t_die < 60)
	{
		ft_error_source(source, "': Invalid argument for time_to_die");
		return (ERROR);
	}
	table->t_die *= 1000;
	return (OK);
}

// we multiply by 1000
// to go from miliseconds to microseconds
int	ft_fill_t_eat(char *source, t_table *table)
{
	if (ft_has_only_pdigit(source) == false
		|| ft_strlen(source) > 10
		|| ft_atoll_safe(source, &table->t_eat) == ERROR
		|| table->t_eat > INT_MAX || table->t_eat < 60)
	{
		ft_error_source(source, "': Invalid argument for time_to_eat");
		return (ERROR);
	}
	table->t_eat *= 1000;
	return (OK);
}

// we multiply by 1000
// to go from miliseconds to microseconds
int	ft_fill_t_sleep(char *source, t_table *table)
{
	if (ft_has_only_pdigit(source) == false
		|| ft_strlen(source) > 10
		|| ft_atoll_safe(source, &table->t_sleep) == ERROR
		|| table->t_sleep > INT_MAX || table->t_sleep < 60)
	{
		ft_error_source(source, "': Invalid argument for time_to_sleep");
		return (ERROR);
	}
	table->t_sleep *= 1000;
	return (OK);
}

int	ft_fill_max_meal(char *source, t_table *table)
{
	if (ft_has_only_pdigit(source) == false
		|| ft_strlen(source) > 10
		|| ft_atoll_safe(source, &table->max_meal) == ERROR
		|| table->max_meal > INT_MAX)
	{
		ft_error_source(source, "': Invalid argument for max_nb_meals");
		return (ERROR);
	}
	return (OK);
}
