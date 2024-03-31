/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:47:34 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/01 00:03:12 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void game_loop(void *ml) // game loop
{
 t_mlx *mlx;

 mlx = ml; // cast to the mlx structure
 mlx_delete_image(mlx->mlx_p, mlx->img); // delete the image
 mlx->img = mlx_new_image(mlx->mlx_p, WIDTH, HEIGHT); // create new image
 hook(mlx, 0, 0); // hook the player
 cast_rays(mlx); // cast the rays
 mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0); // put the image to the window
}

void init_the_player(t_mlx mlx) // init the player structure
{
 mlx.ply->plyr_x = mlx.dt->p_x * TILE_SIZE + TILE_SIZE / 2; // player x position in pixels in the center of the tile
 mlx.ply->plyr_y = mlx.dt->p_y * TILE_SIZE + TILE_SIZE / 2; // player y position in pixels in the center of the tile
 mlx.ply->fov_rd = (FOV * M_PI) / 180; // field of view in radians
 mlx.ply->init_direction = M_PI; // player angle
 //the rest of the variables are initialized to zero by calloc
}

void start_the_game(t_data *dt) // start the game
{
 t_mlx mlx;

 mlx.dt = dt; // init the mlx structure
 mlx.ply = malloc(sizeof(t_player)); // init the player structure i'm using malloc to initialize the variables to zero
 mlx.ray = malloc (sizeof(t_rayon)); // init the ray structure
 mlx.mlx_p = mlx_init(WIDTH, HEIGHT, "Cub3D", 0); // init the mlx pointer and put a window to the screen
 init_the_player(mlx); // init the player structure
 mlx_loop_hook(mlx.mlx_p, &game_loop, &mlx); // game loop continuously call a specified function to update the game state and render the frames.
 mlx_key_hook(mlx.mlx_p, &mlx_key, &mlx); // key press and release
 mlx_loop(mlx.mlx_p); // mlx loop
 ft_exit(&mlx); // exit the game
}

//################################################################################################//
//############################## THE MAIN FUNCTION AND INIT THE MAP ##############################//
//################################################################################################//

t_data *init_argumet() // init the data structure
{
 t_data *dt = malloc (sizeof(t_data)); // init the data structure
 dt->map2d = malloc(10 * sizeof(char *));
 dt->map2d[0] = strdup("1111111111111111111111111"); //fill the map
 dt->map2d[1] = strdup("1000000000000000000100001");
 dt->map2d[2] = strdup("1001000000000P00000000001");
 dt->map2d[3] = strdup("1001000000000000001000001");
 dt->map2d[4] = strdup("1001000000000000001000001");
 dt->map2d[5] = strdup("1001000000100000001000001");
 dt->map2d[6] = strdup("1001000000000000001000001");
 dt->map2d[7] = strdup("1001000000001000001000001");
 dt->map2d[8] = strdup("1111111111111111111111111");
 dt->map2d[9] = NULL;
 dt->p_y = 3; // player y position in the map
 dt->p_x = 14; // player x position in the map
 dt->w_map = 25; // map width
 dt->h_map = 9; // map height
 return (dt); // return the data structure
}


