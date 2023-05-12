/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:38:45 by fsalazar          #+#    #+#             */
/*   Updated: 2023/05/12 14:38:46 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**load_map(char *file)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tmp = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = gnl_strjoin(tmp, line);
		free(line);
	}
	map = ft_split(tmp, '\n');
	free(tmp);
	close(fd);
	return (map);
}

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
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
						* 32, y * 32);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
						game->img_background, x * 32, y * 32);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player,
						x * 32, y * 32);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
						game->img_collectible, x * 32, y * 32);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
						* 32, y * 32);
			x++;
		}
		y++;
	}
	display_moves(game);
	if (game->winner)
		display_winner(game);
	return (0);
}

void	display_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 10, 10, 0x00FFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 70, 10, 0x00FFFFFF, moves);
	free(moves);
}

void	display_winner(t_game *game)
{
	mlx_string_put(game->mlx, game->win, 10, 40, 0x00FFFFFF, "You Win!");
}

void	load_game(t_game *game)
{
	game->mlx = mlx_init();
	ft_printf("MLX Initialized!\n");
	open_window(game);
	ft_printf("Window Opened!\n");
	game->win = mlx_new_window(game->mlx, game->img_width, game->img_height,
			"Not Pac-Man");
	ft_printf("Window Created!\n");
	game->moves = 0;
	game->winner = 0;
	load_graphics(game);
	ft_printf("Graphics Loaded!\n");
	draw_map(game);
	ft_printf("Map Drawn!\n");
}

void	free_arr(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
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
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy(game->mlx);
	system("leaks so_long");
	exit(0);
	return (0);
}
