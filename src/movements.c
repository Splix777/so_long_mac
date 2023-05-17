/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:24:46 by fsalazar          #+#    #+#             */
/*   Updated: 2023/05/17 13:24:49 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_position(t_game *game, char keystroke)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (keystroke == 'a')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"textures/player_left.xpm", &game->img_width,
				&game->img_height);
	else if (keystroke == 'd')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"textures/player_right.xpm", &game->img_width,
				&game->img_height);
	else if (keystroke == 'w')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"textures/player_up.xpm", &game->img_width, &game->img_height);
	else if (keystroke == 's')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"textures/player.xpm", &game->img_width, &game->img_height);
}

void	move_up(t_game *game)
{
	update_position(game, 'w');
	if (game->map[game->player_y][game->player_x] == 'E'
		&& game->collectible == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y + 1][game->player_x] = '0';
		game->winner = 1;
		game->moves++;
		ft_printf("You won in %d moves!\n", game->moves);
		draw_map(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
			|| game->map[game->player_y][game->player_x] == 'E')
		game->player_y += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collectible--;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y + 1][game->player_x] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	move_down(t_game *game)
{
	update_position(game, 's');
	if (game->map[game->player_y][game->player_x] == 'E'
		&& game->collectible == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y - 1][game->player_x] = '0';
		game->winner = 1;
		game->moves++;
		ft_printf("You won in %d moves!\n", game->moves);
		draw_map(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
			|| game->map[game->player_y][game->player_x] == 'E')
		game->player_y -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collectible--;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y - 1][game->player_x] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	move_left(t_game *game)
{
	update_position(game, 'a');
	if (game->map[game->player_y][game->player_x] == 'E'
		&& game->collectible == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y][game->player_x + 1] = '0';
		game->winner = 1;
		game->moves++;
		ft_printf("You won in %d moves!\n", game->moves);
		draw_map(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
			|| game->map[game->player_y][game->player_x] == 'E')
		game->player_x += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collectible--;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x + 1] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	move_right(t_game *game)
{
	update_position(game, 'd');
	if (game->map[game->player_y][game->player_x] == 'E'
		&& game->collectible == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y][game->player_x - 1] = '0';
		game->winner = 1;
		game->moves++;
		ft_printf("You won in %d moves!\n", game->moves);
		draw_map(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
			|| game->map[game->player_y][game->player_x] == 'E')
		game->player_x -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collectible--;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x - 1] = '0';
		game->moves++;
		draw_map(game);
	}
}
