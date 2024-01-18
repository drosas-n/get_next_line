/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:49:05 by drosas-n          #+#    #+#             */
/*   Updated: 2024/01/17 18:08:46 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	x;

	ptr = (char *)malloc(count * size);
	if (!ptr)
		return (0);
	x = 0;
	while (x < count * size)
	{
		ptr[x] = '\0';
		x++;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	len = (ft_strlen(s1) + ft_strlen(s2));
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (0);
	while (s1[x])
	{
		ptr[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		ptr[x + y] = s2[y];
		y++;
	}
	ptr[x + y] = '\0';
	return (ptr);
}

int	ft_strc(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strngcounter(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}
