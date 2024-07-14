/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_engine5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:49:55 by ichettri          #+#    #+#             */
/*   Updated: 2024/07/05 04:14:49 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_src/so_long.h"
#include "../getnextline/get_next_line.h"

int	check_collectables_reachable(t_all *all, int **visited)
{
	int	i;
	int	j;
	int	all_collectibles_reachable;

	i = 0;
	all_collectibles_reachable = 1;
	while (i < all->game->map_height)
	{
		j = 0;
		while (j < all->game->map_width)
		{
			if (all->game->map[i][j] == 'C' && !visited[i][j])
			{
				all_collectibles_reachable = 0;
				break ;
			}
			j++;
		}
		i++;
	}
	return (all_collectibles_reachable);
}

int	valid_pathelper(t_all *all, int **visited)
{
	int	i;
	int	j;
	int	exit_found;
	int	all_collectibles_reachable;

	exit_found = 0;
	all_collectibles_reachable = 1;
	i = 0;
	j = 0;
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
	free_visited(visited, all->game->map_height);
	return (exit_found && all_collectibles_reachable);
}

int	check_valid_path(t_all *all)
{
	int	**visited;

	visited = allocate_visited(all->game->map_height, all->game->map_width);
	if (!visited)
		return (0);
	flood_fill(all->game->player_y, all->game->player_x, all, visited);
	return (valid_pathelper(all, visited));
}

int	check_ber(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	if (str[len - 1] != 'r')
		return (0);
	if (str[len - 2] != 'e')
		return (0);
	if (str[len - 3] != 'b')
		return (0);
	if (str[len - 4] != '.')
		return (0);
	return (1);
}
