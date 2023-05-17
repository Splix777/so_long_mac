/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:25:21 by fsalazar          #+#    #+#             */
/*   Updated: 2023/05/17 14:43:04 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_graphics(t_game *game)
{
	game->img_background = mlx_xpm_file_to_image(game->mlx,
			"textures/background.xpm", &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&game->img_width, &game->img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &game->img_width, &game->img_height);
}

void	open_window(t_game *game)
{
	int	i;

	i = 0;
	game->img_width = ft_strlen(game->map[0]) * 32;
	while (game->map[i] != NULL)
		i++;
	game->img_height = i * 32;
}

void	img_to_window(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, x * 32, y * 32);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_background, x * 32, y * 32);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img_player, x * 32, y * 32);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img_collectible, x * 32, y * 32);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img_exit, x * 32, y * 32);
}

void	load_game(t_game *game)
{
	game->mlx = mlx_init();
	open_window(game);
	game->win = mlx_new_window(game->mlx, game->img_width, game->img_height,
			"Not Pac-Man");
	game->moves = 0;
	game->winner = 0;
	load_graphics(game);
	draw_map(game);
}

int	close_window(t_game *game)
{
	free_arr(game->map);
	mlx_destroy_image(game->mlx, game->img_background);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_collectible);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy(game->mlx);
	exit(0);
	return (0);
}
