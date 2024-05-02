/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:29:53 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/21 22:21:42 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_key_press(mlx_key_data_t keydata, t_general *dt)
{
	if (keydata.key == A && (keydata.action == MLX_PRESS))
		dt->ply->mv.mv[WE] = -1;
	else if (keydata.key == D && (keydata.action == MLX_PRESS))
		dt->ply->mv.mv[EA] = 1;
	else if (keydata.key == S && (keydata.action == MLX_PRESS))
		dt->ply->mv.mv[SO] = -1;
	else if (keydata.key == W && keydata.action == MLX_PRESS)
		dt->ply->mv.mv[NO] = 1;
	else if (keydata.key == LEFT && keydata.action == MLX_PRESS)
		dt->ply->mv.rot = -1;
	else if (keydata.key == RIGHT && keydata.action == MLX_PRESS)
		dt->ply->mv.rot = 1;
}

void	handle_key_release(mlx_key_data_t keydata, t_general *dt)
{
	if ((keydata.key == D || keydata.key == A)
		&& (keydata.action == MLX_RELEASE))
	{
		dt->ply->mv.mv[EA] = 0;
		dt->ply->mv.mv[WE] = 0;
	}
	else if ((keydata.key == S || keydata.key == W)
		&& (keydata.action == MLX_RELEASE))
	{
		dt->ply->mv.mv[SO] = 0;
		dt->ply->mv.mv[NO] = 0;
	}
	else if ((keydata.key == LEFT || keydata.key == RIGHT)
		&& (keydata.action == MLX_RELEASE))
		dt->ply->mv.rot = 0;
}

void	keys(mlx_key_data_t keydata, void *param)
{
	t_config	*dt;

	dt = (t_config *)param;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		clean_exit(EXIT_SUCCESS, "GAME DONE\n", dt);
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		handle_key_press(keydata, dt->dt);
	else if (keydata.action == MLX_RELEASE)
		handle_key_release(keydata, dt->dt);
}
