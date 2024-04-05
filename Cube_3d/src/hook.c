/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 00:38:35 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/04 00:38:53 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_mlx *mlx, int i) // rotate the player
{
	if (i == 1)
	{
		mlx->ply->init_direction += ROTATION_SPEED; // rotate right
		if (mlx->ply->init_direction > 2 * M_PI)
			mlx->ply->init_direction -= 2 * M_PI;
	}
	else
	{
		mlx->ply->init_direction -= ROTATION_SPEED; // rotate left
		if (mlx->ply->init_direction < 0)
			mlx->ply->init_direction += 2 * M_PI;
	}
}

void move_player(t_mlx *mlx, double move_x, double move_y) // move the player
{
 int  map_grid_y;
 int  map_grid_x;
 int  new_x;
 int  new_y;

 new_x = roundf(mlx->ply->plyr_x + move_x); // get the new x position
 new_y = roundf(mlx->ply->plyr_y + move_y); // get the new y position
 map_grid_x = (new_x / TILE_SIZE); // get the x position in the map
 map_grid_y = (new_y / TILE_SIZE); // get the y position in the map
 if (mlx->map->map[map_grid_y][map_grid_x] != '1' && \
 (mlx->map->map[map_grid_y][mlx->ply->plyr_x / TILE_SIZE] != '1' && \
 mlx->map->map[mlx->ply->plyr_y / TILE_SIZE][map_grid_x] != '1')) // check the wall hit and the diagonal wall hit
 {
  mlx->ply->plyr_x = new_x; // move the player
  mlx->ply->plyr_y = new_y; // move the player
 }
}

void hook(t_mlx *mlx, double move_x, double move_y) // hook the player
{
 if (mlx->ply->rot_flag == 1) //rotate right
  rotate_player(mlx, 1);
 if (mlx->ply->rot_flag == -1) //rotate left
  rotate_player(mlx, 0);
 if (mlx->ply->l_r == 1) //move right
 {
  move_x = -sin(mlx->ply->init_direction) * PLAYER_SPEED;
  move_y = cos(mlx->ply->init_direction) * PLAYER_SPEED;
 }
 if (mlx->ply->l_r == -1) //move left
 {
  move_x = sin(mlx->ply->init_direction) * PLAYER_SPEED;
  move_y = -cos(mlx->ply->init_direction) * PLAYER_SPEED;
 }
 if (mlx->ply->u_d == 1) //move up
 {
  move_x = cos(mlx->ply->init_direction) * PLAYER_SPEED;
  move_y = sin(mlx->ply->init_direction) * PLAYER_SPEED;
 }
 if (mlx->ply->u_d == -1) //move down
 {
  move_x = -cos(mlx->ply->init_direction) * PLAYER_SPEED;
  move_y = -sin(mlx->ply->init_direction) * PLAYER_SPEED;
 }
 move_player(mlx, move_x, move_y); // move the player
}