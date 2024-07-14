/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_engine2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:03:25 by ichettri          #+#    #+#             */
/*   Updated: 2024/07/05 03:38:19 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_src/so_long.h"
#include "../getnextline/get_next_line.h"

int	count_rows(char **map)
{
	int	rows;

	rows = 0;
	while (map[rows])
		rows++;
	return (rows);
}

int	count_cols(char *row)
{
	int	cols;

	cols = 0;
	while (*row && *row != '\n' && *row != '\r')
	{
		cols++;
		row++;
	}
	return (cols);
}

int	validate_walls(char **map, int rows, int cols)
{
	int	j;
	int	k;

	if (map[0] == NULL)
		return (error_message("The map is empty.\n"));
	j = 0;
	while (j < cols)
	{
		if (map[0][j] != '1' || map[rows - 1][j] != '1')
			return (error_message("The map must be surrounded by walls!\n"));
		j++;
	}
	k = 0;
	while (k < rows)
	{
		if (map[k][0] != '1' || map[k][cols - 1] != '1')
			return (error_message("The map must be surrounded by walls!\n"));
		k++;
	}
	return (1);
}

void	free_visited(int **visited, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
