/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:38:13 by fsalazar          #+#    #+#             */
/*   Updated: 2023/05/12 14:38:15 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_argv(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] == 'r' && file[i - 2] == 'e'
        && file[i - 3] == 'b' && file[i - 4] == '.')
		return (1);
	return (0);
}

int	valid_map(t_game *game)
{
	int	i;

	i = 0;
	game->collectible = 0;
	game->exit = 0;
	game->player = 0;
	if (is_rectangle(game))
		i++;
	if (has_walls(game))
		i++;
	if (has_pec(game))
		i++;
	if (correct_format(game))
		i++;
	if (i == 4)
		return (1);
	return (0);
}

int	is_rectangle(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j])
			j++;
		if (i == 0)
			game->map_width = j;
		else if (j != game->map_width)
			return (0);
		i++;
	}
	game->map_height = i;
	return (1);
}

int	has_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (i == 0 || i == game->map_height - 1)
			{
				if (game->map[i][j] != '1')
					return (0);
			}
			else if (j == 0 || j == game->map_width - 1)
			{
				if (game->map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	has_pec(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				game->player++;
			}
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'C')
				game->collectible++;
			j++;
		}
		i++;
	}
	if (game->player == 1 && game->exit >= 1 && game->collectible > 0)
		return (1);
	return (0);
}

int	correct_format(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
