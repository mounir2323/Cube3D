/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:48:37 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/28 00:44:28 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotation(t_player *ply, const char *direction)
{
	if (!ft_strncmp(direction, "RIGHT", 5))
	{
		ply->init_dir += ROT_SPEED;
		if (ply->init_dir > 2 * M_PI)
			ply->init_dir -= 2 * M_PI;
	}
	else if (!ft_strncmp(direction, "LEFT", 4))
	{
		ply->init_dir -= ROT_SPEED;
		if (ply->init_dir < 0)
			ply->init_dir += 2 * M_PI;
	}
}

bool	is_valid_move(t_general *mlx, int new_x, int new_y)
{
	int	i;
	int	j;

	i = new_x / TILE_SIZE;
	j = new_y / TILE_SIZE;
	if (new_x < 0 || new_x >= mlx->map->map_max_width * TILE_SIZE
		|| new_y < 0 || new_y >= mlx->map->map_max_height * TILE_SIZE)
		return (false);
	if (mlx->map->map_2d[j][i] != '1' &&
		mlx->map->map_2d[j][mlx->ply->pix_x / TILE_SIZE] != '1' &&
		mlx->map->map_2d[mlx->ply->pix_y / TILE_SIZE][i] != '1')
		return (true);
	return (false);
}

void	move(t_general *mlx, double x_mv, double y_mv)
{
	float	new_x;
	float	new_y;

	new_x = roundf(mlx->ply->pix_x + x_mv);
	new_y = roundf(mlx->ply->pix_y + y_mv);
	if (is_valid_move(mlx, new_x, new_y))
	{
		mlx->ply->pix_x = new_x;
		mlx->ply->pix_y = new_y;
	}
}

void	rotation_hook(t_general *mlx)
{
	if (mlx->ply->mv.rot == 1)
		rotation(mlx->ply, "RIGHT");
	if (mlx->ply->mv.rot == -1)
		rotation(mlx->ply, "LEFT");
}

void	move_hook(t_general *dt, double x_mv, double y_mv)
{
	if (dt->ply->mv.mv[EA] == 1)
	{
		x_mv = -sin(dt->ply->init_dir) * SPEED;
		y_mv = cos(dt->ply->init_dir) * SPEED;
	}
	if (dt->ply->mv.mv[WE] == -1)
	{
		x_mv = sin(dt->ply->init_dir) * SPEED;
		y_mv = -cos(dt->ply->init_dir) * SPEED;
	}
	if (dt->ply->mv.mv[NO] == 1)
	{
		x_mv = cos(dt->ply->init_dir) * SPEED;
		y_mv = sin(dt->ply->init_dir) * SPEED;
	}
	if (dt->ply->mv.mv[SO] == -1)
	{
		x_mv = -cos(dt->ply->init_dir) * SPEED;
		y_mv = -sin(dt->ply->init_dir) * SPEED;
	}
	move(dt, x_mv, y_mv);
}
