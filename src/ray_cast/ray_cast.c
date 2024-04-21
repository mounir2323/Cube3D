/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:48:10 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/20 21:20:06 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	inter_check(double *inter, float ngl, float *sp, bool ishorizon)
{
	if (ishorizon == true)
	{
		if (ngl > 0 && ngl < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*sp *= -1;
	}
	else
	{
		if (!(ngl > M_PI_2 && ngl < 3 * M_PI_2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*sp *= -1;
	}
	return (1);
}

int	hit (float x, float y, t_general *dt)
{
	int	x_on_map;
	int	y_on_map;

	if (x < 0 || y < 0)
		return (0);
	x_on_map = floor (x / TILE_SIZE);
	y_on_map = floor (y / TILE_SIZE);
	if ((y_on_map >= dt->map->map_max_height
			|| x_on_map >= dt->map->map_max_width))
		return (0);
	if (dt->map->map_2d[y_on_map]
		&& (x_on_map <= (int)ft_strlen(dt->map->map_2d[y_on_map])))
		if (dt->map->map_2d[y_on_map][x_on_map] == '1')
			return (0);
	return (1);
}


float	get_horizontal_inter(t_general *gen, float angl)
{
	float	stp_x;
	float	stp_y;
	int		pix;
	double	res;

	stp_y = TILE_SIZE;
	stp_x = TILE_SIZE / tan(angl);
	gen->ray->horiz[Y] = floor(gen->ply->pix_y / TILE_SIZE) * TILE_SIZE;
	pix = inter_check(&gen->ray->horiz[Y], angl, &stp_y, true);
	gen->ray->horiz[X] = gen->ply->pix_x
		+ (gen->ray->horiz[Y] - gen->ply->pix_y) / tan(angl);
	if ((unit_circle(angl, Y) && stp_x > 0)
		|| (!unit_circle(angl, Y) && stp_x < 0))
		stp_x *= -1;
	while (hit(gen->ray->horiz[X], gen->ray->horiz[Y] - pix, gen))
	{
		gen->ray->horiz[X] += stp_x;
		gen->ray->horiz[Y] += stp_y;
	}
	res = sqrt(pow(gen->ray->horiz[X] - gen->ply->pix_x, 2)
			+ pow(gen->ray->horiz[Y] - gen->ply->pix_y, 2));
	return (res);
}


double	get_vertical_inter(t_general *gen, float angl)
{
    float	stp_x;
    float	stp_y;
    int		pix;
	double	res;

    stp_x = TILE_SIZE;
    stp_y = TILE_SIZE * tan(angl);
    gen->ray->vect[X] = floor(gen->ply->pix_x / TILE_SIZE) * TILE_SIZE;
    pix = inter_check(&gen->ray->vect[X], angl, &stp_x, 0);
    gen->ray->vect[Y] = gen->ply->pix_y + (gen->ray->vect[X] - gen->ply->pix_x) * tan(angl);
    if ((unit_circle(angl, X) && stp_y < 0) || (!unit_circle(angl, X) && stp_y > 0))
        stp_y *= -1;
    while (hit(gen->ray->vect[X] - pix, gen->ray->vect[Y], gen))
    {
        gen->ray->vect[X] += stp_x;
        gen->ray->vect[Y] += stp_y;
    }
	res = sqrt(pow(gen->ray->vect[X] - gen->ply->pix_x, 2) 
			+ pow(gen->ray->vect[Y] - gen->ply->pix_y, 2));
    return (res);
}



void	h_v_update(t_general *gen, double h_inter, double v_inter)
{
	gen->ray->flag = false;
	if (v_inter <= h_inter)
		gen->ray->distance = v_inter;
	else
	{
		gen->ray->distance = h_inter;
		gen->ray->flag = true;
	}
}


void	ray_cst(t_general *gen)
{
	int		*ray_ptr;
	int		ray;

	ray = 0;
	ray_ptr = &ray;
	gen->ray->ray_ngl = gen->ply->init_dir - (FOV_RAD / 2);
	while (*ray_ptr < WIDTH)
	{
		h_v_update(gen, \
			get_horizontal_inter(gen, nrm_ngl(gen->ray->ray_ngl)), \
			get_vertical_inter(gen, nrm_ngl(gen->ray->ray_ngl)));
		walls_rend(gen, ray_ptr);
	}
}
