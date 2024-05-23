
#include "ft_printf/libftprintf.h"
#include "gnl/get_next_line.h"
#include "so_long.h"
#include <stdio.h>

void	clear_window(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
}

char	**get_map(t_game *game, char *filename)
{
	char	**map;

	map = read_map(filename);
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
		return (error_message("The map is empty."));
	rows = count_rows(map);
	cols = count_cols(map[0]);
	if (!validate_contents(map, rows, cols))
		return (0);
	if (!validate_walls(map, rows, cols))
		return (0);
	return (1);
}

void	draw_map(t_game *game, t_vars *vars, t_textures *textures)
{
	load_textures(vars, textures);
	draw_tiles(game, vars, textures);
	draw_player(game, vars, textures);
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

	if (argc != 2)
		ft_putstr_fd("Usuage: ./so_long map.ber\n", 1);
	game.map = get_map(&game, argv[1]);
	if (!check_map(game.map))
	{
		ft_putstr_fd("Invalid map.\n", 1);
		return (1);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (game.map_width - 1) * 64,
			(game.map_height * 64), "so_long");
	all.game = &game;
	all.vars = &vars;
	all.textures = &textures;
	all.game->moves = 0;
	mlx_hook(vars.win, 2, 1L << 0, close_window, &vars);
	mlx_hook(vars.win, 17, 1L << 17, terminate_window, &vars);
	draw_map(&game, &vars, &textures);
	mlx_key_hook(vars.win, key_hook, &all);
	mlx_loop(vars.mlx);
}
