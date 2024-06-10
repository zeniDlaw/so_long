/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_engine2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:05:11 by ichettri          #+#    #+#             */
/*   Updated: 2024/05/28 14:30:11 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libftprintf.h"
#include "gnl/get_next_line.h"
#include "so_long.h"

void	update_player_position(t_all *all, int old_x, int old_y)
{
	if (all->game->map[old_y][old_x] != 'E')
		all->game->map[old_y][old_x] = '0';
	draw_tile(all, old_x, old_y);
	move_player(all, all->game->player_x, all->game->player_y);
	draw_tile(all, all->game->player_x, all->game->player_y);
}

void	handle_exit(t_all *all)
{
	ft_printf("Checking exit condition. Collectables remaining: %d\n",
		all->game->collectables);
	if (all->game->collectables != 0)
	{
		write(1, "Collect all the collectables before exiting!!!\n", 48);
		all->game->player_x = all->game->player_x;
		all->game->player_y = all->game->player_y;
		return ;
	}
	ft_printf("You've collected all collectables");
	ft_printf(" and reached the exit! Game Over.");
	ft_printf("\n");
	all->game->map[all->game->player_y][all->game->player_x] = '0';
	exit(0);
}

void	handle_collectable(t_all *all)
{
	all->game->collectables--;
	all->game->map[all->game->player_y][all->game->player_x] = '0';
	ft_printf("Collectable collected. Remaining: %d\n",
		all->game->collectables);
}

void	handle_moves(t_all *all, int old_x, int old_y)
{
	all->game->moves++;
	ft_printf("MOVES: ");
	ft_printf("%d", all->game->moves);
	write(1, "\n", 1);
	if (all->game->map[all->game->player_y][all->game->player_x] == 'C')
		handle_collectable(all);
	else if (all->game->map[all->game->player_y][all->game->player_x] == 'E')
	{
		handle_exit(all);
		return ;
	}
	update_player_position(all, old_x, old_y);
}

void	move_if_valid(t_all *all, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = all->game->player_x;
	old_y = all->game->player_y;
	if (all->game->map[new_y][new_x] != '1')
	{
		all->game->player_x = new_x;
		all->game->player_y = new_y;
		handle_moves(all, old_x, old_y);
	}
}
    