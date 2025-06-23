/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:37:49 by *******           #+#    #+#             */
/*   Updated: 2025/05/11 22:30:03 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

bool	ft_has_only_pdigit(char *str)
{
	size_t	i;

	if (!str || ft_is_empty_str(str))
		return (false);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (false);
		i++;
	}
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_is_empty_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_space(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

void	ft_print_banner(void)
{
	printf(BOLD"" RED"\n           [ "
		ORANGE"S" YELLOW"T" GREEN"A" TEAL"R" BLUE"T" PURPLE" ]\n\n");
}

int	ft_table_end_check(t_table *table)
{
	int		err_code;
	bool	ret;

	err_code = pthread_mutex_lock(&table->end_lock);
	if (err_code)
		return (ft_error_mtx_lock(err_code));
	ret = table->end;
	err_code = pthread_mutex_unlock(&table->end_lock);
	if (err_code)
		return (ft_error_mtx_unlock(err_code));
	return (ret);
}
