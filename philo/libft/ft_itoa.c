/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:14:51 by *******           #+#    #+#             */
/*   Updated: 2025/05/12 22:51:58 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static void		ft_recursive_fill(size_t i, char *ret, long long n);
static size_t	ft_llonglen(long long n);

char	*ft_itoa(long long n)
{
	size_t	length;
	size_t	i;
	char	*ret;

	length = ft_llonglen(n);
	ret = malloc(sizeof(char) * (length + 1));
	if (ret == NULL)
		return (NULL);
	ret[length] = '\0';
	i = 0;
	if (n == 0)
	{
		ret[i] = '0';
		return (ret);
	}
	if (n < 0)
	{
		ret[i] = '-';
		i++;
		n = -(n);
	}
	ft_recursive_fill((length - 1), ret, n);
	return (ret);
}

static void	ft_recursive_fill(size_t length, char *ret, long long n)
{
	if (n >= 10 && length > 0)
	{
		ft_recursive_fill((length - 1), ret, n / 10);
	}
	ret[length] = (n % 10) + 48;
}

static size_t	ft_llonglen(long long n)
{
	size_t	sum;

	sum = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -(n);
		sum++;
	}
	while (n > 0)
	{
		n /= 10;
		sum++;
	}
	return (sum);
}
