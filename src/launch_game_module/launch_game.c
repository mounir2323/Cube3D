/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:18:05 by schibane          #+#    #+#             */
/*   Updated: 2024/04/20 20:42:58 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	game(void *param)
{
	t_general	*dt;

	dt = (t_general*)param;

	mlx_delete_image(dt->mlx->mlx_p, dt->mlx->img);
	dt->mlx->img = mlx_new_image(dt->mlx->mlx_p, WIDTH, HEIGHT);
	move_hook(dt, 0, 0);
	rotation_hook(dt);
	ray_cst(dt);
	mlx_image_to_window(dt->mlx->mlx_p, dt->mlx->img, 0, 0);
}

void	launch_game(t_general *dt, t_config cnf)
{
	dt->map = init_map(cnf);
	dt->ply = init_ply(dt->map, cnf);
	dt->ray = init_ray(cnf);
	dt->mlx = malloc(sizeof(t_mlx));
	if (!dt->mlx)
		clean_exit(EXIT_FAILURE, "MALLOC ERR\n", &cnf);
	dt->mlx->mlx_p = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	load_png(dt->mlx, cnf);
	mlx_loop_hook(dt->mlx->mlx_p, &game, dt);
	mlx_key_hook(dt->mlx->mlx_p, &keys, &cnf);
	mlx_loop(dt->mlx->mlx_p);
}
