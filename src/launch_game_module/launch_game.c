/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:18:05 by schibane          #+#    #+#             */
/*   Updated: 2024/04/28 00:43:34 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game(void *param)
{
	t_general	*dt;

	dt = (t_general *)param;
	mlx_delete_image(dt->mlx->mlx_p, dt->mlx->img);
	dt->mlx->img = mlx_new_image(dt->mlx->mlx_p, WIDTH, HEIGHT);
	move_hook(dt, 0, 0);
	rotation_hook(dt);
	ray_cst(dt);
	mlx_image_to_window(dt->mlx->mlx_p, dt->mlx->img, 0, 0);
}

t_general	*init_general(t_config *conf)
{
	t_general	*dt;

	dt = malloc(sizeof(t_general));
	if (!dt)
		clean_exit(1, "Malloc ERR\n", conf);
	dt->map = NULL;
	dt->mlx = NULL;
	dt->ray = NULL;
	dt->ply = NULL;
	return (dt);
}

void	init_mlx_obj(t_config cnf)
{
	int	i;

	i = -1;
	cnf.dt->mlx = malloc(sizeof(t_mlx));
	if (!cnf.dt->mlx)
		clean_exit(EXIT_FAILURE, "MALLOC ERR\n", &cnf);
	cnf.dt->mlx->mlx_p = NULL;
	cnf.dt->mlx->img = NULL;
	while (++ i < 4)
		cnf.dt->mlx->walls[i] = NULL;
	cnf.dt->mlx->mlx_p = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
}

void	launch_game(t_config cnf)
{
	cnf.dt = init_general(&cnf);
	cnf.dt->map = init_map(cnf);
	cnf.dt->ply = init_ply(cnf.dt->map, cnf);
	cnf.dt->ray = init_ray(cnf);
	init_mlx_obj(cnf);
	load_png(cnf.dt->mlx, cnf);
	mlx_loop_hook(cnf.dt->mlx->mlx_p, &game, cnf.dt);
	mlx_key_hook(cnf.dt->mlx->mlx_p, &keys, &cnf);
	mlx_loop(cnf.dt->mlx->mlx_p);
}
