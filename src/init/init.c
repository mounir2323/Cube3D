/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:50:26 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/20 20:39:50 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <string.h>

// {
// 	if (dir == 'N')
// 	{
// 		data->dir_vect.dir_x = 0;
// 		data->dir_vect.dir_y = -1;
// 		data->cam_vect.dir_x = FOV;
// 		data->cam_vect.dir_y = 0;
// 	}
// 	else if (dir == 'S')
// 	{
// 		data->dir_vect.dir_x = 0;
// 		data->dir_vect.dir_y = 1;
// 		data->cam_vect.dir_x = -1 * FOV;
// 		data->cam_vect.dir_y = 0;
// 	}
// 	else if (dir == 'E')
// 	{
// 		data->dir_vect.dir_x = -1;
// 		data->dir_vect.dir_y = 0;
// 		data->cam_vect.dir_x = 0;
// 		data->cam_vect.dir_y = -1 * FOV;
// 	}
// 	else
// 	{
// 		data->dir_vect.dir_x = 1;
// 		data->dir_vect.dir_y = 0;
// 		data->cam_vect.dir_x = 0;
// 		data->cam_vect.dir_y = FOV;
// 	}
// }

uint32_t	rgb_to_hex(uint8_t r, uint8_t g, uint8_t b) 
{
	uint32_t	hex_color;

	r = (r > 255) ? 255 : (r < 0) ? 0 : r;
    g = (g > 255) ? 255 : (g < 0) ? 0 : g;
    b = (b > 255) ? 255 : (b < 0) ? 0 : b;
    hex_color = (r << 16) | (g << 8) | b;
	hex_color = (hex_color << 8) | 0xFF;

   return (hex_color);
}

t_map *init_map(t_config cnf) // init the data structure
{
	t_map *map = malloc(sizeof(t_map)); // init the data structure
	map->map_2d = malloc(10 * sizeof(char *)); // init the map
 
 map->map_2d[0] = strdup("111111111111111111111111111111111"); //fill the map
 map->map_2d[1] = strdup("1001000000100000000000000000000");
 map->map_2d[2] = strdup("1001000000100P00000000000000001");
 map->map_2d[3] = strdup("000100000010000000000000000000001");
 map->map_2d[4] = strdup("1001000000100000000000001000001");
 map->map_2d[5] = strdup("1001110111100000000000000000001");
 map->map_2d[6] = strdup("1000000000000000000000000011");
 map->map_2d[7] = strdup("10000000000000000000000000111");
 map->map_2d[8] = strdup("1111111111111111111111111");
 map->map_2d[9] = NULL;
//  map->map_2d[10] = NULL;
 map->p_y = 3; 
 map->p_x = 14;
 map->map_max_width =33;
 map->map_max_height = 9;

	map->clr_ceil = rgb_to_hex(cnf.c[RED], cnf.c[GREEN], cnf.c[BLUE]);
	map->clr_floor = rgb_to_hex(cnf.f[RED], cnf.f[GREEN], cnf.f[BLUE]);
 return (map);
}


t_rayon	*init_ray(t_config cnf) 
{
	t_rayon	*ray;

	ray = malloc(sizeof(t_rayon));
	if (!ray)
		clean_exit(EXIT_FAILURE, "MALLOC ERR\n", &cnf);
	ray->distance = 0;
	ray->ray_ngl = 0;
	ray->flag = false;

	return (ray);
}

double	init_dir(t_config cnf)
{
	double	dir;

	dir = M_PI;
	if (cnf.player_pos.dir == 'E')
		dir = 0;
	else if (cnf.player_pos.dir == 'N')
		dir = M_PI_2;
	else if (cnf.player_pos.dir == 'S')
		dir = 3 * M_PI_2;
	return (dir);
}


t_player	*init_ply(t_map *map, t_config cnf)
{
	t_player	*p;

	p = malloc(sizeof(t_player));
	if (!p)
		clean_exit(EXIT_FAILURE, "MALLOC ERR\n", &cnf);
	p->pix_x = map->p_x * TILE_SIZE + TILE_SIZE / 2;
	p->pix_y = map->p_y * TILE_SIZE + TILE_SIZE / 2;
	p->init_dir = init_dir(cnf);
	p->mv.mv[NO] = 0;
	p->mv.mv[SO] = 0;
	p->mv.mv[EA] = 0;
	p->mv.mv[WE] = 0;
	p->mv.rot = 0;
	return (p);
}

