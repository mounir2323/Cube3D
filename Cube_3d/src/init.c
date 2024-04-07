/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:47:34 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/07 03:50:22 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void game_loop(void *ml) // game loop
// {
// 	t_mlx *mlx;
	
// 	mlx = ml; // cast to the mlx structure
// 	mlx_delete_image(mlx->mlx_p, mlx->img); // delete the image
// 	mlx->img = mlx_new_image(mlx->mlx_p, WIDTH, HEIGHT); // create new image
// 	hook(mlx, 0, 0); // hook the player
// 	cast_rays(mlx); // cast the rays
// 	mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0); // put the image to the window
// }

// void init_the_player(t_mlx mlx) // init the player structure
// {
//  mlx.ply->plyr_x = mlx.map->p_x * TILE_SIZE +  TILE_SIZE / 2  ;// player x position in pixels in the center of the tile
//  mlx.ply->plyr_y = mlx.map->p_y * TILE_SIZE +  TILE_SIZE / 2; // player y position in pixels in the center of the tile
//  mlx.ply->init_direction = M_PI; // player angle
// }


t_map *init_map2d(void)
{
	t_map	*map;

	map = malloc (sizeof(t_map));
	map->map = malloc(10 * sizeof(char *));
	map->map[0] = strdup("1111111111111111111111111");
	map->map[1] = strdup("1000000000000000000000001");
	map->map[2] = strdup("1001000000000S00000000001");
	map->map[3] = strdup("1001000000000000001000001");
	map->map[4] = strdup("1001000000000000001000001");
	map->map[5] = strdup("1001000000100000001000001");
	map->map[6] = strdup("1001000000000000001000001");
	map->map[7] = strdup("1001000000001000001000001");
	map->map[8] = strdup("1111111111111111111111111");
	map->map[9] = NULL;
	map->p_y = 3;
	map->p_x = 14;
	map->map_width = 25;
	map->map_height = 9;
	map->wall[0] = mlx_load_png("/Users/mtayebi/Desktop/Cub3D_mygit/Cube_3d/texture/1.png");
	map->wall[1] = mlx_load_png("/Users/mtayebi/Desktop/Cub3D_mygit/Cube_3d/texture/2.png");
	map->wall[2] = mlx_load_png("/Users/mtayebi/Desktop/Cub3D_mygit/Cube_3d/texture/3.png");
	map->wall[3] = mlx_load_png("/Users/mtayebi/Desktop/Cub3D_mygit/Cube_3d/texture/4.png");
	return (map);
}
t_player *init_ply(t_gen *gen) // init the player in tile structure
{
	t_player *ply;
	
	ply = malloc(sizeof(t_player));
		if(!ply)
		{
			free(gen);
			return (NULL) ;
		}
 	ply->plyr_x = 14 * TILE_SIZE + TILE_SIZE / 2; //add the funct  
 	ply->plyr_y = 3 * TILE_SIZE + TILE_SIZE / 2; // ****
 	ply->init_direction = M_PI; // player init direction
	return (ply);
}

t_rayon *init_ray(t_gen *gen)
{
	t_rayon *ray;
	
	ray = malloc(sizeof(t_rayon));
    if (!ray) 
	{
        free(gen->p);
        free(gen->map);
        free(gen);
        return NULL;
    }
	ray->distance = 0;
	ray->flag = 0;
	ray->ray_ngl = 0;
	return (ray);
}

t_gen	*init_args(void)
{
	t_gen *gen;

	gen = malloc(sizeof(t_gen));
	gen->map = init_map2d();
	gen->p = init_ply(gen);
	gen->ray = init_ray(gen);
	
	return (gen);
}