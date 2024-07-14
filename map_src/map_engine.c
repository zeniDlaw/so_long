/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:02:12 by ichettri          #+#    #+#             */
/*   Updated: 2024/07/05 03:38:14 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_src/so_long.h"
#include "../getnextline/get_next_line.h"

char	**read_map(char *filename)
{
	int		fd;
	char	**map;

	fd = open_map_file(filename);
	map = allocate_map();
	read_lines(fd, map);
	close(fd);
	return (map);
}

void	process_map(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	game->collectables = 0;
	game->map_width = ft_strlen(map[0]);
	game->map_height = 0;
	while (map[game->map_height])
		game->map_height++;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			else if (map[i][j] == 'C')
				game->collectables++;
			j++;
		}
		i++;
	}
}

int	error_message(char *message)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(message, 1);
	return (0);
}

int	is_valid_char(char c, int *player_count, int *exit_count)
{
	if (c == 'P')
		(*player_count)++;
	else if (c == 'E')
		(*exit_count)++;
	else if (c != '1' && c != '0' && c != 'C')
		return (error_message("Invalid character in map!\n"));
	return (1);
}

int	validate_contents(char **map, int rows, int cols)
{
	int	player_count;
	int	exit_count;
	int	i;
	int	j;

	player_count = 0;
	exit_count = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		if (count_cols(map[i]) != cols)
			return (error_message("All rows must have the same length!\n"));
		while (j < cols)
		{
			if (!is_valid_char(map[i][j], &player_count, &exit_count))
				return (0);
			j++;
		}
		i++;
	}
	if (player_count != 1 || exit_count != 1)
		return (error_message("Must need a player and one exit!\n"));
	return (1);
}
