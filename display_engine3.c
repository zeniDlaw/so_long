/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_engine3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:04:07 by ichettri          #+#    #+#             */
/*   Updated: 2024/05/27 17:52:24 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libftprintf.h"
#include "gnl/get_next_line.h"
#include "so_long.h"

void	draw_tile_helper(t_all *all, int x, int y)
{
	char	map_char;

	map_char = all->game->map[y][x];
	if (map_char == '1')
		mlx_put_image_to_window(all->vars->mlx, all->vars->win,
			all->textures->wall, x * 64, y * 64);
	else if (map_char == '0')
		mlx_put_image_to_window(all->vars->mlx, all->vars->win,
			all->textures->floor, x * 64, y * 64);
	else if (map_char == 'C')
		mlx_put_image_to_window(all->vars->mlx, all->vars->win,
			all->textures->collectables, x * 64, y * 64);
	else if (map_char == 'E')
		mlx_put_image_to_window(all->vars->mlx, all->vars->win,
			all->textures->exit, x * 64, y * 64);
}
