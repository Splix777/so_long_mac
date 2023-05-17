/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:25:12 by fsalazar          #+#    #+#             */
/*   Updated: 2023/05/17 13:25:13 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dup_map(t_game *game)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (game->map_height + 1));
	while (i < game->map_height)
	{
		map[i] = ft_strdup(game->map[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	check_surrounding(char **map, int y, int x)
{
	if (map[y][x - 1] == 'X' || map[y][x + 1] == 'X' || map[y - 1][x] == 'X'
		|| map[y + 1][x] == 'X')
		return (1);
	return (0);
}

void	flood_fill(t_game *game, char **map, int y, int x)
{
	if (y < 0 || x < 0 || y >= game->map_height || x >= game->map_width)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'C' || map[y][x] == 'E')
		return ;
	if (map[y][x] == '0' || map[y][x] == 'P')
	{
		if (map[y][x] == '0')
			map[y][x] = 'X';
		flood_fill(game, map, y + 1, x);
		flood_fill(game, map, y - 1, x);
		flood_fill(game, map, y, x + 1);
		flood_fill(game, map, y, x - 1);
	}
}

int	has_valid_path(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	game->valid_path = 0;
	map = dup_map(game);
	flood_fill(game, map, game->player_y, game->player_x);
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if ((map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'P')
				&& !check_surrounding(map, i, j))
				game->valid_path = -1;
			j++;
		}
		i++;
	}
	free_arr(map);
	if (game->valid_path == -1)
		return (0);
	return (1);
}
