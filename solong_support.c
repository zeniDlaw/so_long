/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_support.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:49:34 by ichettri          #+#    #+#             */
/*   Updated: 2024/05/23 18:10:24 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "so_long.h"

int	terminate_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	close_window(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	move_player(t_all *all, int x, int y)
{
	int		old_x;
	int		old_y;
	char	new_tile;

	old_x = all->game->player_x;
	old_y = all->game->player_y;
	new_tile = all->game->map[y][x];
	draw_tile(all, old_x, old_y);
	if (new_tile == 'E' && all->game->collectables > 0)
	{
		draw_tile(all, old_x, old_y);
		return ;
	}
	all->game->player_x = x;
	all->game->player_y = y;
	draw_tile(all, old_x, old_y);
	draw_tile(all, x, y);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
