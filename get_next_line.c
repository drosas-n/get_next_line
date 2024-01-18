/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:43:55 by drosas-n          #+#    #+#             */
/*   Updated: 2024/01/18 15:54:45 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static char	*cleaner(char *stat_str)
{
	char	*temp;
	int		len;
	int		i;

	len = ft_strlen(stat_str);
	i = ft_strngcounter(stat_str, '\n');
	temp = ft_calloc(len - i + 1, sizeof(char));
	if (!temp)
	{
		free(temp);
		free(stat_str);
		return (NULL);
	}
	i++;
	len = 0;
	while (stat_str[i])
	{
		temp[len++] = stat_str[i++];
	}
	temp[len] = '\0';
	free(stat_str);
	return (temp);
}

static char	*good_line(char *stat_str)
{
	char	*temp;
	int		i;

	i = 0;
	if (!stat_str)
		return (NULL);
	while (stat_str[i] != '\n' && stat_str[i] != '\0')
		i++;
	temp = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (stat_str[i] != '\n' && stat_str[i] != '\0')
	{
		temp[i] = stat_str[i];
		i++;
	}
	temp[i] = '\n';
	temp[++i] = '\0';
	return (temp);
}

static char	*get_all(int fd, char *stat_str)
{
	char	*temp;
	int		reader;

	temp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	reader = 1;
	if (!stat_str)
		stat_str = ft_calloc(1, sizeof(char));
	while (reader > 0)
	{
		reader = read(fd, temp, BUFFER_SIZE);
		stat_str = ft_strjoin(stat_str, temp);
		if (ft_strc(temp, '\n'))
			break ;
	}
	free(temp);
	return (stat_str);
}

char	*get_next_line(int fd)
{
	static char	*stat_str;
	char		*real_line;

	if (!fd)
		return (NULL);
	stat_str = get_all(fd, stat_str);
	real_line = good_line(stat_str);
	stat_str = cleaner(stat_str);
	return (real_line);
}

int	main(void)
{
	int	fd = open("archivo.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
