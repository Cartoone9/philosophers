/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:26:27 by *******           #+#    #+#             */
/*   Updated: 2025/05/12 17:51:45 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static int	ft_eat_handler_even(t_philo *philo);
static int	ft_eat_handler_odd(t_philo *philo);

int	ft_eat(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		if (ft_eat_handler_even(philo) == ERROR)
			return (ERROR);
	}
	else
	{
		if (ft_eat_handler_odd(philo) == ERROR)
			return (ERROR);
	}
	return (OK);
}

static int	ft_eat_handler_even(t_philo *philo)
{
	int	status;

	status = ft_try_acquire_left_spoon(philo, true);
	if (status == ERROR)
		return (ERROR);
	if (status == 1)
		return (status);
	status = ft_try_acquire_right_spoon(philo, true);
	if (status == ERROR)
		return (ERROR);
	if (status == 1)
		return (status);
	return (ft_actions_while_holding_spoons(philo));
}

static int	ft_eat_handler_odd(t_philo *philo)
{
	int	status;

	status = ft_try_acquire_right_spoon(philo, false);
	if (status == ERROR)
		return (ERROR);
	if (status == 1)
		return (status);
	status = ft_try_acquire_left_spoon(philo, false);
	if (status == ERROR)
		return (ERROR);
	if (status == 1)
		return (status);
	return (ft_actions_while_holding_spoons(philo));
}

int	ft_sleep(t_philo *philo)
{
	ft_print_status(philo, GREEN"is sleeping"RESET);
	if (ft_usleep_improved(philo->table->t_sleep, philo->table) == ERROR)
		return (ERROR);
	return (OK);
}

int	ft_think(t_philo *philo)
{
	ft_print_status(philo, TEAL"is thinking"RESET);
	if (philo->table->n_philo % 2 != 0)
	{
		if (ft_usleep_improved(philo->table->t_eat / 10, philo->table) == ERROR)
			return (ERROR);
	}
	return (OK);
}
