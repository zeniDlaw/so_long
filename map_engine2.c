/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_engine2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:13:58 by ichettri          #+#    #+#             */
/*   Updated: 2024/05/23 13:28:43 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libftprintf.h"
#include "gnl/get_next_line.h"
#include "so_long.h"

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

	j = 0;
	while (j < cols)
	{
		if (map[0][j] != '1' || map[rows - 1][j] != '1')
			return (error_message("The map must be surrounded by walls!"));
		j++;
	}
	k = 0;
	while (k < rows)
	{
		if (map[k][0] != '1' || map[k][cols - 1] != '1')
			return (error_message("The map must be surrounded by walls!"));
		k++;
	}
	return (1);
}
