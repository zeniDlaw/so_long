/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_engine5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:49:55 by ichettri          #+#    #+#             */
/*   Updated: 2024/06/10 20:50:15 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libftprintf.h"
#include "gnl/get_next_line.h"
#include "so_long.h"

int	check_valid_path(t_all *all)
{
	int	**visited;
	int	result;

	perform_flood_fill(all, &visited);
	if (!visited)
		return (0);
	result = check_path(all, visited);
	free_visited(visited, all->game->map_height);
	return (result);
}
