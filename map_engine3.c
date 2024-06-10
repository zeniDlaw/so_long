/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_engine3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:07:55 by ichettri          #+#    #+#             */
/*   Updated: 2024/06/10 20:50:32 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libftprintf.h"
#include "gnl/get_next_line.h"
#include "so_long.h"

void	free_failed(int i, int **visited)
{
	while (i > 0)
	{
		free(visited[--i]);
	}
	free(visited);
}

int	**allocate_visited(int rows, int cols)
{
	int	**visited;
	int	i;

	i = 0;
	visited = (int **)malloc(rows * sizeof(int *));
	if (!visited)
		return (NULL);
	while (i < rows)
	{
		visited[i] = (int *)malloc(cols * sizeof(int));
		if (!visited[i])
		{
			free_failed(i, visited);
			return (NULL);
		}
		ft_memset(visited[i], 0, cols * sizeof(int));
		i++;
	}
	return (visited);
}

void	flood_fill(int x, int y, t_all *all, int **visited)
{
	if (x < 0 || x >= all->game->map_height || y < 0
		|| y >= all->game->map_width || visited[x][y]
		|| all->game->map[x][y] == '1')
	{
		return ;
	}
	visited[x][y] = 1;
	flood_fill(x + 1, y, all, visited);
	flood_fill(x - 1, y, all, visited);
	flood_fill(x, y + 1, all, visited);
	flood_fill(x, y - 1, all, visited);
}

void	perform_flood_fill(t_all *all, int ***visited)
{
	*visited = allocate_visited(all->game->map_height, all->game->map_width);
	if (!*visited)
		return ;
	flood_fill(all->game->player_y, all->game->player_x, all, *visited);
}

int	check_path(t_all *all, int **visited)
{
	int	exit_found;
	int	all_collectibles_reachable;
	int	i;
	int	j;

	exit_found = 0;
	all_collectibles_reachable = 1;
	i = 0;
	while (i < all->game->map_height)
	{
		j = 0;
		while (j < all->game->map_width)
		{
			if (all->game->map[i][j] == 'E' && visited[i][j])
				exit_found = 1;
			if (all->game->map[i][j] == 'C' && !visited[i][j])
				all_collectibles_reachable = 0;
			j++;
		}
		i++;
	}
	return (exit_found && all_collectibles_reachable);
}
