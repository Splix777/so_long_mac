/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:38:58 by fsalazar          #+#    #+#             */
/*   Updated: 2023/05/12 14:38:59 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc == 2)
    {
        game.map = load_map(argv[1]);
        if (valid_argv(argv[1]) && valid_map(&game))
        {
            ft_printf("Map is Valid!\n");
            load_game(&game);
            play_game(&game);
            mlx_loop(game.mlx);
        }
        else
        {
            ft_printf("Error: Invalid Map Format!\n");
            if (game.map)
            {
                ft_printf("Freeing Map...\n");
                free_arr(game.map);
            }
            system("leaks so_long");
            return (0);
        }
    }
    else
    {
        ft_printf("Error: Invalid Number of Arguments!\n");
        return (0);
    }
    system("leaks so_long");
    return (0);
}



