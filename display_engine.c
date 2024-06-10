/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:04:01 by ichettri          #+#    #+#             */
/*   Updated: 2024/05/28 14:26:56 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libftprintf.h"
#include "gnl/get_next_line.h"
#include "so_long.h"

void	load_textures(t_vars *vars, t_textures *textures)
{
	int	i;

	i = 0;
	textures->wall = mlx_xpm_file_to_image(vars->mlx, "textures/tree.xpm", &i,
			&i);
	textures->floor = mlx_xpm_file_to_image(vars->mlx, "textures/Floor.xpm", &i,
			&i);
	textures->collectables = mlx_xpm_file_to_image(vars->mlx,
			"textures/textscroll.xpm", &i, &i);
	textures->player = mlx_xpm_file_to_image(vars->mlx, "textures/walk0.xpm",
			&i, &i);
	textures->exit = mlx_xpm_file_to_image(vars->mlx, "textures/castle.xpm", &i,
			&i);
}

void	draw_tile(t_all *all, int x, int y)
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
	if (x == all->game->player_x && y == all->game->player_y)
		mlx_put_image_to_window(all->vars->mlx, all->vars->win,
			all->textures->player, x * 64, y * 64);
}

void	draw_tiles(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->game->map_height)
	{
		x = 0;
		while (x < all->game->map_width)
		{
			draw_tile_helper(all, x, y);
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *game, t_vars *vars, t_textures *textures)
{
	mlx_put_image_to_window(vars->mlx, vars->win, textures->player,
		game->player_x * 64, game->player_y * 64);
}

void	determine_new_position(int keycode, int *new_x, int *new_y)
{
	if (keycode == 'w' || keycode == 'W')
		*new_y -= 1;
	else if (keycode == 'a' || keycode == 'A')
		*new_x -= 1;
	else if (keycode == 's' || keycode == 'S')
		*new_y += 1;
	else if (keycode == 'd' || keycode == 'D')
		*new_x += 1;
}
