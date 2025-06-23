/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:38:37 by *******           #+#    #+#             */
/*   Updated: 2025/05/06 16:52:16 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

void	ft_error(char *error_msg)
{
	char	*full_error_msg;

	full_error_msg = ft_strjoin(error_msg, "\n");
	if (!full_error_msg)
	{
		write(2, RED "Error\n" RESET, 28);
		write(2, error_msg, ft_strlen(error_msg));
		write(2, "\n", 1);
	}
	else
	{
		write(2, RED "Error\n" RESET, 28);
		write(2, full_error_msg, ft_strlen(full_error_msg));
		free(full_error_msg);
	}
}

void	ft_error_min(char *error_msg)
{
	char	*full_error_msg;

	full_error_msg = ft_strjoin(error_msg, "\n");
	if (!full_error_msg)
	{
		write(2, error_msg, ft_strlen(error_msg));
		write(2, "\n", 1);
	}
	else
	{
		write(2, full_error_msg, ft_strlen(full_error_msg));
		free(full_error_msg);
	}
}

void	ft_error_source(char *source, char *error_msg)
{
	char	*full_error_msg;

	full_error_msg = ft_strjoin_four("philo: '", source, error_msg, "\n");
	if (!full_error_msg)
	{
		write(2, RED "Error\n" RESET, 28);
		write(2, error_msg, ft_strlen(error_msg));
		write(2, "\n", 1);
	}
	else
	{
		write(2, RED "Error\n" RESET, 28);
		write(2, full_error_msg, ft_strlen(full_error_msg));
		free(full_error_msg);
	}
}

void	ft_error_arg(void)
{
	ft_error("philo: ./philo nb_philosophers "
		"time_to_die time_to_eat time_to_sleep "
		"[max_nb_meals]");
}
