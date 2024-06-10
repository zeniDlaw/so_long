/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:40:22 by ichettri          #+#    #+#             */
/*   Updated: 2024/01/10 12:43:45 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cpy_it(char *ptr, char *str, int i, int j)
{
	i = 0;
	j++;
	while (str[j])
		ptr[i++] = str[j++];
	ptr[i] = '\0';
	free(str);
}

char	*all_if(int i, char *buf, char *str, char *tmp)
{
	char	*temp;

	temp = NULL;
	buf[i] = '\0';
	tmp = str;
	if (!tmp)
	{
		tmp = malloc(sizeof(char) * 1);
		tmp[0] = '\0';
	}
	temp = ft_strjoin(tmp, buf);
	free(tmp);
	return (temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str1;
	char	*str2;
	char	*ptr;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2);
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (NULL);
	while (*str1)
	{
		*ptr++ = *str1++;
	}
	while (*str2)
	{
		*ptr++ = *str2++;
	}
	*ptr = '\0';
	return ((char *)ptr - len);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
