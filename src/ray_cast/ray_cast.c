/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:48:10 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/28 00:52:20 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_intr(t_ray_info *info, float ngl, bool flag, bool ishorizon)
{
	if (ishorizon)
	{
		if (ngl > 0 && ngl < M_PI)
		{
			if (flag == VECT)
				info->vect += TILE_SIZE;
			else
				info->horiz += TILE_SIZE;
			return (-1);
		}
	}
	else
	{
		if (!(ngl > M_PI_2 && ngl < 3 * M_PI_2))
		{
			if (flag == VECT)
				info->vect += TILE_SIZE;
			else
				info->horiz += TILE_SIZE;
			return (-1);
		}
	}
	info->step *= -1;
	return (1);
}

int	hit(float x, float y, t_general *dt)
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
	int		pix;
	double	res;

	gen->info[Y].step = TILE_SIZE;
	gen->info[X].step = gen->info[Y].step / tan(angl);
	gen->info[Y].horiz = floor(gen->ply->pix_y / gen->info[Y].step)
		* gen->info[Y].step;
	pix = check_intr(&gen->info[Y], angl, HORIZ, true);
	gen->info[X].horiz = gen->ply->pix_x
		+ (gen->info[Y].horiz - gen->ply->pix_y) / tan(angl);
	if ((u_circle(angl, Y) && gen->info[X].step > 0)
		|| (!u_circle(angl, Y) && gen->info[X].step < 0))
		gen->info[X].step *= -1;
	while (hit(gen->info[X].horiz, gen->info[Y].horiz - pix, gen))
	{
		gen->info[X].horiz += gen->info[X].step;
		gen->info[Y].horiz += gen->info[Y].step;
	}
	res = sqrt(pow(gen->info[X].horiz - gen->ply->pix_x, 2)
			+ pow(gen->info[Y].horiz - gen->ply->pix_y, 2));
	return (res);
}

double	get_vertical_inter(t_general *gen, float angl)
{
	int		pix;
	double	res;

	gen->info[X].step = TILE_SIZE;
	gen->info[Y].step = gen->info[X].step * tan(angl);
	gen->info[X].vect = floor(gen->ply->pix_x / gen->info[X].step)
		* gen->info[X].step;
	pix = check_intr(&gen->info[X], angl, VECT, 0);
	gen->info[Y].vect = gen->ply->pix_y
		+ (gen->info[X].vect - gen->ply->pix_x) * tan(angl);
	if ((u_circle(angl, X) && gen->info[Y].step < 0)
		|| (!u_circle(angl, X) && gen->info[Y].step > 0))
		gen->info[Y].step *= -1;
	while (hit(gen->info[X].vect - pix, gen->info[Y].vect, gen))
	{
		gen->info[X].vect += gen->info[X].step;
		gen->info[Y].vect += gen->info[Y].step;
	}
	res = sqrt(pow(gen->info[X].vect - gen->ply->pix_x, 2)
			+ pow(gen->info[Y].vect - gen->ply->pix_y, 2));
	return (res);
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
