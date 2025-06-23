/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:37:49 by *******           #+#    #+#             */
/*   Updated: 2025/04/28 15:44:10 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

bool	ft_is_space(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (true);
	else
		return (false);
}

bool	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

bool	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (true);
	if (c >= 'A' && c <= 'Z')
		return (true);
	else
		return (false);
}

bool	ft_is_alphanum(int c)
{
	if (c >= 'a' && c <= 'z')
		return (true);
	if (c >= 'A' && c <= 'Z')
		return (true);
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}
