/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mtx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:38:37 by *******           #+#    #+#             */
/*   Updated: 2025/05/06 16:45:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

int	ft_error_mtx_init(int err_code)
{
	if (err_code == EAGAIN)
		ft_error_min("The system lacked the necessary resources "
			"(other than memory) to initialise another mutex.");
	else if (err_code == ENOMEM)
		ft_error_min("Insufficient memory exists to initialise the mutex.");
	else if (err_code == EPERM)
		ft_error_min("The caller does not have the privilege "
			"to perform the operation.");
	else if (err_code == EBUSY)
		ft_error_min("The implementation has detected an attempt to "
			"re-initialise the object referenced by mutex, "
			"a previously initialised, but not yet destroyed, mutex.");
	else if (err_code == EINVAL)
		ft_error_min("The value specified by attr is invalid.");
	return (ERROR);
}

int	ft_error_mtx_destroy(int err_code)
{
	if (err_code == EAGAIN)
		ft_error_min("The system lacked the necessary resources "
			"(other than memory) to initialise another mutex.");
	else if (err_code == ENOMEM)
		ft_error_min("Insufficient memory exists to initialise the mutex.");
	else if (err_code == EPERM)
		ft_error_min("The caller does not have the privilege "
			"to perform the operation.");
	else if (err_code == EBUSY)
		ft_error_min("The implementation has detected an attempt "
			"to destroy the object referenced by mutex while "
			"it is locked or referenced by another thread");
	else if (err_code == EINVAL)
		ft_error_min("The value specified by mutex is invalid.");
	return (ERROR);
}

int	ft_error_mtx_lock(int err_code)
{
	if (err_code == EINVAL)
		ft_error_min("The value specified by mutex does not refer "
			"to an initialised mutex object.");
	else if (err_code == EAGAIN)
		ft_error_min("The mutex could not be acquired because "
			"the maximum number of recursive locks "
			"for mutex has been exceeded.");
	else if (err_code == EDEADLK)
		ft_error_min("The current thread already owns the mutex.");
	return (ERROR);
}

int	ft_error_mtx_unlock(int err_code)
{
	if (err_code == EINVAL)
		ft_error_min("The value specified by mutex does not refer "
			"to an initialised mutex object.");
	else if (err_code == EAGAIN)
		ft_error_min("The mutex could not be acquired because "
			"the maximum number of recursive locks "
			"for mutex has been exceeded.");
	else if (err_code == EPERM)
		ft_error_min("The current thread does not own the mutex.");
	return (ERROR);
}
