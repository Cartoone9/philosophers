/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:26:27 by *******           #+#    #+#             */
/*   Updated: 2025/05/05 14:56:52 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

int	ft_tester_table(t_table *table)
{
	printf("\n--- TESTER TABLE ---\n\n");
	printf("n_philo : %lli\n", table->n_philo);
	printf("t_die : %lli\n", table->t_die);
	printf("t_eat : %lli\n", table->t_eat);
	printf("t_sleep : %lli\n", table->t_sleep);
	printf("max_meal : %lli\n", table->max_meal);
	printf("start_time : %lli\n", table->start_time);
	printf("end : %i\n", table->end);
	printf("\n--- TESTER TABLE ---\n\n");
	return (0);
}
