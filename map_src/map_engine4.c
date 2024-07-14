/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_engine4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:17:40 by ichettri          #+#    #+#             */
/*   Updated: 2024/07/05 03:38:27 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_src/so_long.h"
#include "../getnextline/get_next_line.h"

int	open_map_file(char *filename)
{
	char	*full_path;
	int		fd;

	full_path = ft_strjoin("maps/", filename);
	if (!full_path)
	{
		ft_putstr_fd("Error: Memory allocation failed.\n", 1);
		exit(1);
	}
	fd = open(full_path, O_RDONLY);
	free(full_path);
	if (fd < 0)
	{
		ft_putstr_fd("Error: Cannot open map file.\n", 1);
		exit(1);
	}
	return (fd);
}

char	**allocate_map(void)
{
	char	**map;

	map = malloc(sizeof(char *) * (MAX_MAP_HEIGHT + 1));
	if (!map)
	{
		ft_putstr_fd("Error: Memory allocation failed.\n", 1);
		exit(1);
	}
	return (map);
}

void	is_empty(char **map)
{
	ft_printf("Error: Map is Empty.\n");
	free_map(map);
	exit(1);
}

void	read_lines(int fd, char **map)
{
	int	y;

	y = 0;
	while (1)
	{
		map[y] = get_next_line(fd);
		if (!map[y])
			break ;
		if (ft_strlen(map[y]) > MAX_MAP_WIDTH)
		{
			ft_putstr_fd("Error: Map width out of bounds.\n", 1);
			exit(1);
		}
		y++;
		if (y > MAX_MAP_HEIGHT)
		{
			ft_putstr_fd("Error: Map height out of bounds.\n", 1);
			exit(1);
		}
	}
	if (y == 0)
		is_empty(map);
	map[y] = NULL;
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		len--;
	}
	return (b);
}
