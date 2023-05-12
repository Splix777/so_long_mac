/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:38:35 by fsalazar          #+#    #+#             */
/*   Updated: 2023/05/12 14:38:36 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_game
{
    void    *mlx;
    void    *win;
    void    *img_background;
    void    *img_wall;
    void    *img_player;
    void    *img_exit;
    void    *img_collectible;
    char    **map;
    int     map_width;
    int     map_height;
    int     img_width;
    int     img_height;
    int     player_x;
    int     player_y;
    int     collectible;
    int     player;
    int     exit;
    int     moves;
    int     winner;
}            t_game;

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
// Map Checkers
int     valid_argv(char *file);
int     valid_map(t_game *game);
int     has_walls(t_game *game);
int     has_pec(t_game *game);
int     is_rectangle(t_game *game);
int     correct_format(t_game *game);
// Map Loaders and Handlers
char    **load_map(char *file);
void    load_graphics(t_game *game);
void    open_window(t_game *game);
void    load_game(t_game *game);
void    free_arr(char **map);
void    display_moves(t_game *game);
void    display_winner(t_game *game);
int close_window(t_game *game);
int draw_map(t_game *game);
// Gameplay
void    play_game(t_game *game);
void    player_movements(int keycode, t_game *game);
int key_press(int keycode, t_game *game);
// Movements
void    update_position(t_game *game, char keystroke);
void    move_up(t_game *game);
void    move_down(t_game *game);
void    move_left(t_game *game);
void    move_right(t_game *game);

#endif
