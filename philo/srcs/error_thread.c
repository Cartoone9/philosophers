/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:38:37 by *******           #+#    #+#             */
/*   Updated: 2025/05/11 20:46:53 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

int	ft_error_thread_crt(int err_code)
{
	if (err_code == EAGAIN)
		ft_error_min("Insufficient resources to create another thread.");
	else if (err_code == EINVAL)
		ft_error_min("Invalid settings in attr.");
	else if (err_code == EPERM)
		ft_error_min("No permission to set the scheduling policy "
			"and parameters specified in attr.");
	return (ERROR);
}

int	ft_error_thread_dtch(int err_code)
{
	if (err_code == EINVAL)
		ft_error_min("The thread is not a joinable thread.");
	else if (err_code == ESRCH)
		ft_error_min("No thread with the ID thread could be found.");
	return (ERROR);
}

int	ft_error_thread_join(int err_code)
{
	if (err_code == ESRCH)
		ft_error_min("The thread is not a joinable thread.");
	else if (err_code == EDEADLK)
		ft_error_min("No thread with the ID thread could be found.");
	else if (err_code == EINVAL)
		ft_error_min("The value specified by thread does not "
			"refer to a joinable thread.");
	return (ERROR);
}
