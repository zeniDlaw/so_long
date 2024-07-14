/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_src2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:07:11 by ichettri          #+#    #+#             */
/*   Updated: 2024/07/05 03:34:38 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_src/so_long.h"

void	handle_agruments(int argc, char *filename)
{
	if (argc != 2)
	{
		ft_putstr_fd("Usuage: ./so_long map2.ber\n", 1);
		exit(1);
	}
	else if (!(check_ber(filename)))
	{
		ft_putstr_fd("Invalid file extension. Please use a .ber file.\n", 1);
		exit(1);
	}
}

void	initialize_game(t_game *game, t_all *all, char *filename)
{
	game->map = get_map(game, filename);
	if (!game->map || !check_map(game->map))
	{
		ft_putstr_fd("Invalid map.\n", 1);
		free_map(game->map);
		exit(1);
	}
	ft_printf("Player position: (%d, %d)\n", game->player_y, game->player_x);
	all->game = game;
}

void	validate_path(t_all *all)
{
	if (!check_valid_path(all))
	{
		ft_printf("No valid path exists from the player to the exit.\n");
		free_map(all->game->map);
		exit(1);
	}
}

void	setup_graphics(t_vars *vars, t_game *game)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (game->map_width - 1) * 64,
			game->map_height * 64, "so_long");
}

void	register_hooks(t_vars *vars, t_all *all)
{
	mlx_hook(vars->win, 2, 1L << 0, close_window, vars);
	mlx_hook(vars->win, 17, 1L << 17, terminate_window, vars);
	mlx_key_hook(vars->win, key_hook, all);
}
