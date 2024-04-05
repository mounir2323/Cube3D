/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:47:34 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/05 01:12:00 by mtayebi          ###   ########.fr       */
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
 mlx.ply->plyr_x = mlx.map->p_x * TILE_SIZE +  TILE_SIZE / 2  ;// player x position in pixels in the center of the tile
 mlx.ply->plyr_y = mlx.map->p_y * TILE_SIZE +  TILE_SIZE / 2; // player y position in pixels in the center of the tile
 mlx.ply->init_direction = M_PI; // player angle
}


