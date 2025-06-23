/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:17:21 by *******           #+#    #+#             */
/*   Updated: 2025/05/16 15:57:56 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static int	ft_printf_manual(long long time, int philo_id, char *status);
static char	*ft_build_final_str(long long time, int philo_id, char *status);

int	ft_print_status(t_philo *philo, char *status)
{
	long long	curr_time;
	long long	time;
	int			err_code;
	int			ret;

	curr_time = ft_gettime_ms();
	if (curr_time == ERROR)
		return (ERROR);
	time = curr_time - philo->table->start_time;
	err_code = pthread_mutex_lock(&philo->table->print_lock);
	if (err_code)
		return (ft_error_mtx_lock(err_code));
	if (ft_philo_end_check(philo) == true
		&& ft_strncmp(status, RED "died" RESET, ft_strlen(status)))
	{
		err_code = pthread_mutex_unlock(&philo->table->print_lock);
		if (err_code)
			return (ft_error_mtx_unlock(err_code));
		return (OK);
	}
	ret = ft_printf_manual(time, philo->philo_id, status);
	err_code = pthread_mutex_unlock(&philo->table->print_lock);
	if (err_code)
		return (ft_error_mtx_unlock(err_code));
	return (ret);
}

/* OLD PRINTF LINE : */
/*printf(BOLD""GREY"[%llu] "RESET"philo nº%i %s\n", time,*/
/*	philo->philo_id, status);*/

static int	ft_printf_manual(long long time, int philo_id, char *status)
{
	char	*final_str;

	final_str = ft_build_final_str(time, philo_id, status);
	if (final_str == NULL)
		return (ERROR);
	write(1, final_str, ft_strlen(final_str));
	free(final_str);
	return (OK);
}

static char	*ft_build_final_str(long long time, int philo_id, char *status)
{
	char	*itoa_ret;
	char	*time_str;
	char	*philo_id_str;
	char	*final_str;

	itoa_ret = ft_itoa(time);
	if (itoa_ret == NULL)
		return (NULL);
	time_str = ft_strjoin_time(itoa_ret);
	free(itoa_ret);
	if (time_str == NULL)
		return (NULL);
	itoa_ret = ft_itoa(philo_id);
	if (itoa_ret == NULL)
		return (free(time_str), NULL);
	philo_id_str = ft_strjoin("philo nº", itoa_ret);
	free(itoa_ret);
	if (philo_id_str == NULL)
		return (free(time_str), NULL);
	final_str = ft_strjoin_print(time_str, philo_id_str, status);
	free(time_str);
	free(philo_id_str);
	if (!final_str)
		return (NULL);
	return (final_str);
}
