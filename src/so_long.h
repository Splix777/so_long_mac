/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:24:56 by fsalazar          #+#    #+#             */
/*   Updated: 2023/05/17 13:24:58 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_background;
	void	*img_wall;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	char	**map;
	int		valid_path;
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	int		collectible;
	int		player;
	int		exit;
	int		moves;
	int		error;
	int		winner;
}			t_game;

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

# define KEY_ESC 53
# define KEY_Q 12
// Valid ARGV
int			valid_argv(char *file);
// Valid Map
int			valid_map(t_game *game);
int			is_rectangle(t_game *game);
int			has_walls(t_game *game);
void		has_pec(t_game *game);
int			correct_format(t_game *game);
// Valid Path
char		**dup_map(t_game *game);
void		flood_fill(t_game *game, char **map, int y, int x);
int			check_surroundings(char **map, int i, int j);
int			has_valid_path(t_game *game);
// Utils
void		free_arr(char **arr);
char		**load_map(char *file);
void		display_moves(t_game *game);
// Gameplay
void		key_press(int keycode, t_game *game);
int			keystroke(int keycode, t_game *game);
void		play_game(t_game *game);
// Graphical
void		load_graphics(t_game *game);
void		open_window(t_game *game);
void		img_to_window(t_game *game, int x, int y);
int			draw_map(t_game *game);
void		load_game(t_game *game);
int			close_window(t_game *game);
// Movements
void		update_position(t_game *game, char keystroke);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);

#endif
