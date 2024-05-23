/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:08:20 by ichettri          #+#    #+#             */
/*   Updated: 2024/05/23 18:10:38 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MAX_MAP_SIZE 100

# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
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
	void		*win_screen;
}				t_textures;

typedef struct s_all
{
	t_game		*game;
	t_vars		*vars;
	t_textures	*textures;
}				t_all;

int				count_rows(char **map);
int				count_cols(char *row);
int				validate_walls(char **map, int rows, int cols);
int				error_message(char *message);
int				is_valid_char(char c, int *player_count, int *exit_count);
int				validate_contents(char **map, int rows, int cols);
char			**read_map(char *filename);
void			process_map(t_game *game, char **map);
int				check_map(char **map);
void			load_textures(t_vars *vars, t_textures *textures);
void			draw_tiles(t_game *game, t_vars *vars, t_textures *textures);
void			draw_player(t_game *game, t_vars *vars, t_textures *textures);
void			handle_moves(t_all *all, int old_x, int old_y);
void			determine_new_position(int keycode, int *new_x, int *new_y);
void			update_player_position(t_all *all, int old_x, int old_y);
void			handle_collectable(t_all *all);
void			handle_exit(t_all *all);
void			move_if_valid(t_all *all, int new_x, int new_y);
int				terminate_window(t_vars *vars);
void			draw_tile(t_all *all, int x, int y);
int				close_window(int keycode, t_vars *vars);
void			move_player(t_all *all, int x, int y);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putstr_fd(char *s, int fd);

#endif
