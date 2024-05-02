/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:06:29 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/28 00:53:43 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	reverse_bytes(int c)
{
	return ((c & 0xFF) << 24 | (c & 0xFF00) << 8 | \
		(c & 0xFF0000) >> 8 | (c & 0xFF000000) >> 24);
}

float	nrm_ngl(float angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

int	u_circle(float angle, int axis)
{
	if ((axis == 0 && (angle > 0 && angle < M_PI))
		|| (axis == 1 && (angle > M_PI_2 && angle < 3 * M_PI_2)))
		return (1);
	return (0);
}

void	get_params(t_general *gen)
{
	gen->ray->distance *= cos(nrm_ngl(gen->ray->ray_ngl - gen->ply->init_dir));
	gen->params.wall_h = (TILE_SIZE / gen->ray->distance)
		* ((WIDTH / 2) / tan(FOV_RAD / 2));
	gen->params.bottom_p = (HEIGHT / 2) + (gen->params.wall_h / 2);
	if (gen->params.bottom_p > HEIGHT)
		gen->params.bottom_p = HEIGHT;
	gen->params.top_pix = (HEIGHT / 2) - (gen->params.wall_h / 2);
	if (gen->params.top_pix < 0)
		gen->params.top_pix = 0;
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
