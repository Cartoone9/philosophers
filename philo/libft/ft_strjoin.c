/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:54:04 by *******           #+#    #+#             */
/*   Updated: 2025/05/12 23:21:10 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static size_t	ft_strcpy_helper(char *ret, size_t i, const char *src);

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin_time(const char *time)
{
	char	*ret;
	size_t	ret_len;
	size_t	i;
	size_t	j;

	if (!time)
		return (NULL);
	ret_len = ft_strlen(BOLD) + ft_strlen(GREY) + ft_strlen(time) + 2;
	ret = malloc(sizeof(char) * (ret_len + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (BOLD[i])
		ret[i++] = BOLD[j++];
	j = 0;
	while (GREY[j])
		ret[i++] = GREY[j++];
	ret[i++] = '[';
	j = 0;
	while (time[j])
		ret[i++] = time[j++];
	ret[i++] = ']';
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin_print(const char *s1, const char *s2, const char *s3)
{
	char	*ret;
	size_t	len;
	size_t	i;

	if (!s1 || !s2 || !s3)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(RESET) + ft_strlen(s2) + ft_strlen(s3) + 3;
	ret = malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	i = ft_strcpy_helper(ret, 0, s1);
	i = ft_strcpy_helper(ret, i, RESET);
	ret[i++] = ' ';
	i = ft_strcpy_helper(ret, i, s2);
	ret[i++] = ' ';
	i = ft_strcpy_helper(ret, i, s3);
	ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

static size_t	ft_strcpy_helper(char *ret, size_t i, const char *src)
{
	size_t	j;

	j = 0;
	while (src[j])
	{
		ret[i] = src[j];
		i++;
		j++;
	}
	return (i);
}

char	*ft_strjoin_four(const char *s1, const char *s2, const char *s3,
		const char *s4)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!s1 || !s2 || !s3 || !s4)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3)
				+ ft_strlen(s4) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ret[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ret[i++] = s2[j++];
	j = 0;
	while (s3[j])
		ret[i++] = s3[j++];
	j = 0;
	while (s4[j])
		ret[i++] = s4[j++];
	ret[i] = '\0';
	return (ret);
}
