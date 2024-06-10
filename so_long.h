/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:59:11 by ichettri          #+#    #+#             */
/*   Updated: 2024/06/10 20:52:06 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MAX_MAP_WIDTH 60
# define MAX_MAP_HEIGHT 33

# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_game
{
	char		**map;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	int			collectables;
	int			moves;
	int			old_x;
	int			old_y;
}				t_game;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img_ptr;
	int			img_x;
	int			img_y;
}				t_vars;

typedef struct s_textures
{
	void		*wall;
	void		*floor;
	void		*collectables;
	void		*player;
	void		*exit;
}				t_textures;

typedef struct s_all
{
	t_game		*game;
	t_vars		*vars;
	t_textures	*textures;
}				t_all;

void			handle_agruments(int argc);
void			initialize_game(t_game *game, t_all *all, char *filename);
void			validate_path(t_all *all);
void			setup_graphics(t_vars *vars, t_game *game);
void			register_hooks(t_vars *vars, t_all *all);
int				open_map_file(char *filename);
char			**allocate_map(void);
void			read_lines(int fd, char **map);
int				count_rows(char **map);
int				count_cols(char *row);
int				validate_walls(char **map, int rows, int cols);
int				error_message(char *message);
int				is_valid_char(char c, int *player_count, int *exit_count);
int				validate_contents(char **map, int rows, int cols);
char			**read_map(char *filename);
void			process_map(t_game *game, char **map);
int				check_map(char **map);
char			**get_map(t_game *game, char *filename);
int				key_hook(int keycode, t_all *all);
void			load_textures(t_vars *vars, t_textures *textures);
void			draw_tiles(t_all *all);
void			draw_player(t_game *game, t_vars *vars, t_textures *textures);
void			handle_moves(t_all *all, int old_x, int old_y);
void			determine_new_position(int keycode, int *new_x, int *new_y);
void			update_player_position(t_all *all, int old_x, int old_y);
void			handle_collectable(t_all *all);
void			handle_exit(t_all *all);
void			move_if_valid(t_all *all, int new_x, int new_y);
int				terminate_window(t_vars *vars);
void			draw_tile_helper(t_all *all, int x, int y);
void			draw_tile(t_all *all, int x, int y);
int				close_window(int keycode, t_vars *vars);
void			move_player(t_all *all, int x, int y);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putstr_fd(char *s, int fd);
void			find_player_position(t_game *game);
int				**allocate_visited(int rows, int cols);
void			free_visited(int **visited, int rows);
void			flood_fill(int x, int y, t_all *all, int **visited);
int				check_valid_path(t_all *all);
void			free_map(char **map);
void			*ft_memset(void *b, int c, size_t len);
int				check_path(t_all *all, int **visited);
void			perform_flood_fill(t_all *all, int ***visited);

#endif
