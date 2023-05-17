/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:24:39 by fsalazar          #+#    #+#             */
/*   Updated: 2023/05/17 13:24:40 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			img_to_window(game, x, y);
			x++;
		}
		y++;
	}
	display_moves(game);
	return (0);
}

void	key_press(int keycode, t_game *game)
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

int	keystroke(int keycode, t_game *game)
{
	if (!game)
		return (0);
	else if (keycode == KEY_ESC || keycode == KEY_Q)
		close_window(game);
	else if (game->winner == 0)
	{
		ft_printf("Moves: %d\n", game->moves);
		key_press(keycode, game);
	}
	else if (game->winner == 1)
	{
		ft_printf("You won in %d moves!\n", game->moves);
		close_window(game);
	}
	return (0);
}

void	play_game(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, keystroke, game);
	mlx_hook(game->win, 17, 1L << 17, close_window, game);
	mlx_hook(game->win, 9, 1L << 21, draw_map, game);
}
