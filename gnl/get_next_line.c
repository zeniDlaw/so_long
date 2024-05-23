/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:37:10 by ichettri          #+#    #+#             */
/*   Updated: 2024/04/16 18:51:18 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

// #include <stdio.h>

char	*ft_before(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[0] == '\0')
	{
		return (NULL);
	}
	ptr = malloc(sizeof(char) * i + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ptr[i++] = '\n';
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_after(char *str)
{
	int		i;
	int		j;
	char	*ptr;

	j = 0;
	i = ft_strlen(str);
	if (!str)
		return (NULL);
	while (str[j] != '\n' && str[j])
		j++;
	if (str[j] == '\0')
	{
		free(str);
		return (NULL);
	}
	ptr = malloc(sizeof(char) * (i - j));
	if (!ptr)
	{
		free(str);
		return (NULL);
	}
	cpy_it(ptr, str, i, j);
	return (ptr);
}

int	ft_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_read(int fd, char *buf, char *tmp, char *str)
{
	int		i;
	char	*temp;

	i = 1;
	while (i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		temp = all_if(i, buf, str, tmp);
		if (!temp)
		{
			free(str);
			return (NULL);
		}
		str = temp;
		if (ft_newline(str) == 1)
			break ;
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str = ft_read(fd, buf, tmp, str);
	if (!str)
		return (NULL);
	line = ft_before(str);
	str = ft_after(str);
	return (line);
}
