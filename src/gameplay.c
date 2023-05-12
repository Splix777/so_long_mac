/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:38:21 by fsalazar          #+#    #+#             */
/*   Updated: 2023/05/12 14:38:23 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_movements(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->player_y -= 1;
		move_up(game);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->player_y += 1;
		move_down(game);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->player_x -= 1;
		move_left(game);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->player_x += 1;
		move_right(game);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (!game)
		return (0);
	else if (game->winner == 1)
		close_window(game);
	else if (keycode == KEY_ESC || keycode == KEY_Q)
		close_window(game);
	else
		player_movements(keycode, game);
	return (0);
}

void	play_game(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 17, 1L << 17, close_window, game);
	mlx_hook(game->win, 9, 1L << 21, draw_map, game);
}
