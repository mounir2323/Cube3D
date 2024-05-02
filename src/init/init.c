/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:50:26 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/28 00:43:57 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	rgb_to_hex(uint8_t r, uint8_t g, uint8_t b)
{
	uint32_t	hex_color;

	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;
	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;
	if (b > 255)
		b = 255;
	if (b < 0)
		b = 0;
	hex_color = (r << 16) | (g << 8) | b;
	hex_color = (hex_color << 8) | 0xFF;
	return (hex_color);
}

t_map	*init_map(t_config cnf)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		clean_exit(1, "Malloc error\n", &cnf);
	map->map_2d = cnf.map;
	map->p_y = cnf.player_pos.i;
	map->p_x = cnf.player_pos.j;
	map->map_max_width = cnf.biggest_mapline;
	map->map_max_height = str_tab_len(map->map_2d) - 2;
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
		dir = 3 * M_PI_2;
	else if (cnf.player_pos.dir == 'S')
		dir = M_PI_2;
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
