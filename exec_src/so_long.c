/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:00:58 by ichettri          #+#    #+#             */
/*   Updated: 2024/07/05 03:45:07 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_src/so_long.h"
#include "../getnextline/get_next_line.h"

char	**get_map(t_game *game, char *filename)
{
	char	**map;

	map = read_map(filename);
	if (!map)
		return (NULL);
	process_map(game, map);
	return (map);
}

int	check_map(char **map)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	if (!map || !map[0])
		return (error_message("The map is empty.\n"));
	if (map[0] != NULL)
	{
		cols = count_cols(map[0]);
		rows = count_rows(map);
		ft_printf("rows : %d, cols : %d\n", rows, cols);
		if (!validate_contents(map, rows, cols))
			return (0);
		if (!validate_walls(map, rows, cols))
			return (0);
	}
	return (1);
}

void	draw_map(t_all *all, t_vars *vars, t_textures *textures)
{
	load_textures(vars, textures);
	draw_tiles(all);
	draw_player(all->game, vars, textures);
}

int	key_hook(int keycode, t_all *all)
{
	int	new_x;
	int	new_y;

	new_x = all->game->player_x;
	new_y = all->game->player_y;
	if (keycode == 'w' || keycode == 'W' || keycode == 'a' || keycode == 'A'
		|| keycode == 's' || keycode == 'S' || keycode == 'd' || keycode == 'D')
	{
		determine_new_position(keycode, &new_x, &new_y);
		move_if_valid(all, new_x, new_y);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_vars		vars;
	t_textures	textures;
	t_all		all;

	handle_agruments(argc, argv[1]);
	initialize_game(&game, &all, argv[1]);
	validate_path(&all);
	setup_graphics(&vars, &game);
	all.vars = &vars;
	all.textures = &textures;
	all.game->moves = 0;
	draw_map(&all, &vars, &textures);
	register_hooks(&vars, &all);
	mlx_loop(vars.mlx);
	free_map(game.map);
	return (0);
}
